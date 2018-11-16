#include "ShaderProgram.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "Material.h"
#include <glm/ext.hpp>
#include <fstream>
#include <iostream>

namespace Aspect
{
	namespace Engine
	{
		ShaderProgram::ShaderProgram(std::string vert, std::string frag)
		{
			std::ifstream file(vert.c_str());
			std::string vertSrc;

			if (!file.is_open())
			{
				throw std::exception();
			}

			while (!file.eof())
			{
				std::string line;
				std::getline(file, line);
				vertSrc += line + "\n";
			}

			file.close();
			file.open(frag.c_str());
			std::string fragSrc;

			if (!file.is_open())
			{
				throw std::exception();
			}

			while (!file.eof())
			{
				std::string line;
				std::getline(file, line);
				fragSrc += line + "\n";
			}

			const GLchar *vs = vertSrc.c_str();
			GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vertexShaderId, 1, &vs, NULL);
			glCompileShader(vertexShaderId);
			GLint success = 0;
			glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);

			if (!success)
			{
				GLint maxLength = 0;
				glGetShaderiv(vertexShaderId, GL_INFO_LOG_LENGTH, &maxLength);

				// The maxLength includes the NULL character
				std::vector<GLchar> errorLog(500);
				glGetShaderInfoLog(vertexShaderId, maxLength, &maxLength, &errorLog[0]);
				std::cout << &errorLog.at(0) << std::endl;
				throw std::exception();
			}

			const GLchar *fs = fragSrc.c_str();
			GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fragmentShaderId, 1, &fs, NULL);
			glCompileShader(fragmentShaderId);
			glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);

			if (!success)
			{
				throw std::exception();
			}

			id = glCreateProgram();
			glAttachShader(id, vertexShaderId);
			glAttachShader(id, fragmentShaderId);
			glBindAttribLocation(id, 0, "in_Position");
			glBindAttribLocation(id, 1, "in_Color");
			glBindAttribLocation(id, 2, "in_TexCoord");
			glBindAttribLocation(id, 3, "in_Normal");


			if (glGetError() != GL_NO_ERROR)
			{
				throw std::exception();
			}

			glLinkProgram(id);
			glGetProgramiv(id, GL_LINK_STATUS, &success);

			if (!success)
			{
				throw std::exception();
			}

			glDetachShader(id, vertexShaderId);
			glDeleteShader(vertexShaderId);
			glDetachShader(id, fragmentShaderId);
			glDeleteShader(fragmentShaderId);
		}

		void ShaderProgram::draw(std::shared_ptr<VertexArray> vArray)
		{
			glUseProgram(id);
			glBindVertexArray(vArray->getId());

			for (size_t i = 0; i < samplers.size(); i++)
			{
				glActiveTexture(GL_TEXTURE0 + i);

				if (samplers.at(i).mat)
				{
					glBindTexture(GL_TEXTURE_2D, samplers.at(i).mat->getId());
				}
				else
				{
					glBindTexture(GL_TEXTURE_2D, 0);
				}
			}

			glDrawArrays(GL_TRIANGLES, 0, vArray->getVertexCount());

			for (size_t i = 0; i < samplers.size(); i++)
			{
				glActiveTexture(GL_TEXTURE0 + i);
				glBindTexture(GL_TEXTURE_2D, 0);
			}

			glBindVertexArray(0);
			glUseProgram(0);
		}

		void ShaderProgram::setUniform(std::string uniform, glm::vec4 value)
		{
			GLint uniformId = glGetUniformLocation(id, uniform.c_str());

			if (uniformId == -1)
			{
				throw std::exception();
			}

			glUseProgram(id);
			glUniform4f(uniformId, value.x, value.y, value.z, value.w);
			glUseProgram(0);
		}

		void ShaderProgram::setUniform(std::string uniform, float value)
		{
			GLint uniformId = glGetUniformLocation(id, uniform.c_str());

			if (uniformId == -1)
			{
				throw std::exception();
			}

			glUseProgram(id);
			glUniform1f(uniformId, value);
			glUseProgram(0);
		}

		void ShaderProgram::setUniform(std::string uniform, glm::mat4 value)
		{
			GLint uniformId = glGetUniformLocation(id, uniform.c_str());

			if (uniformId == -1)
			{
				throw std::exception();
			}

			glUseProgram(id);
			glUniformMatrix4fv(uniformId, 1, GL_FALSE, glm::value_ptr(value));
			glUseProgram(0);
		}

		void ShaderProgram::setUniform(std::string uniform, std::shared_ptr<Material> mat)
		{
			GLint uniformId = glGetUniformLocation(id, uniform.c_str());

			if (uniformId == -1)
			{
				throw std::exception();
			}

			for (size_t i = 0; i < samplers.size(); i++)
			{
				if (samplers.at(i).id == uniformId)
				{
					samplers.at(i).mat = mat;

					glUseProgram(id);
					glUniform1i(uniformId, i);
					glUseProgram(0);
					return;
				}
			}

			Sampler s;
			s.id = uniformId;
			s.mat = mat;
			samplers.push_back(s);

			glUseProgram(id);
			glUniform1i(uniformId, samplers.size() - 1);
			glUseProgram(0);
		}

		GLuint ShaderProgram::getId()
		{
			return id;
		}

	}
	

}