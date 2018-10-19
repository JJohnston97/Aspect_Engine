
#include "Audio.h"
#include <AL/al.h>
#include <vorbis/vorbisfile.h>
#include <iostream>
#include <vector>

namespace Aspect
{
	namespace Engine
	{
		struct SoundClip
		{
			ALuint id;

			~SoundClip()
			{
				alDeleteBuffers(1, &id);
			}

			void load_ogg(std::string fileName, std::vector<char> &buffer, ALenum &format, ALsizei &freq)
			{
				int endian = 0;
				int bitStream = 0;
				long bytes = 0;
				char array[2048] = { 0 };
				vorbis_info *pInfo = NULL;
				OggVorbis_File oggFile = { 0 };

				// Inbuilt Fopen to create a file descriptor
				if (ov_fopen(fileName.c_str(), &oggFile) != 0)
				{
					std::cout << "Failed to open file: " << fileName << " For decoding" << std::endl;
					throw std::exception();
				}

				// Take the info from the file header
				pInfo = ov_info(&oggFile, -1);

				// Record the format required by OpenAL
				if (pInfo->channels == 1)
				{
					format = AL_FORMAT_MONO16;
				}
				else
				{
					format = AL_FORMAT_STEREO16;
				}

				// record the sample rate required by OpenAL
				freq = pInfo->rate;

				// Keep reading bytes from the file to populate the output buffer
				while (true)
				{
					// Read bytes into temporary a array
					bytes = ov_read(&oggFile, array, 2048, endian, 2, 1, &bitStream);

					if (bytes < 0)
					{
						ov_clear(&oggFile);
						std::cout << "Failed to decode file: " << fileName << "." << std::endl;
						throw std::exception();
					}
					else if (bytes == 0)
					{
						break;

					}

					// Copy From temporary array into output buffer
					buffer.insert(buffer.end(), array, array + bytes);
				}

				ov_clear(&oggFile);
			}

		};

		Audio::Audio() {}

		Audio::Audio(std::string path) // Give the audio a string for file name
		{
			load(path); 
		}

		void Audio::load(std::string path)
		{
			Sclip = std::make_shared<SoundClip>();
			ALenum format = 0;
			ALsizei freq = 0;
			std::vector<char> bufferData;
			alGenBuffers(1, &Sclip->id);
			Sclip->load_ogg(path.c_str(), bufferData, format, freq);
			alBufferData(Sclip->id, format, &bufferData[0], static_cast<ALsizei>(bufferData.size()), freq);

		}

		void Audio::play()
		{
			ALuint sid = 0;
			alGenSources(1, &sid);
			alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
			alSource3f(sid, AL_POSITION, 0.0f, 0.0f, 0.0f);
			alSourcei(sid, AL_BUFFER, Sclip->id);
			alSourcePlay(sid);
		
		// AudioSources.push_back(sid) when you have a vector of sounds
		}
	
		void Audio::play(float vol, float varMin, float varMax)
		{
			//For Btter rand resolution
			varMin *= 1000.0f;
			varMax *= 1000.0f;
			float variance = (std::rand() % ((int)varMin + 1 - (int)varMax) + (int)varMin) / 1000.0f;
			// Want to return ^ std::rand() % (max + 1 - min) + min;

			ALuint sid = 0;
			alGenSources(1, &sid);
			alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
			alSource3f(sid, AL_POSITION, 0.0f, 0.0f, 0.0f);
			alSourcei(sid, AL_BUFFER, Sclip->id);
			alSourcef(sid, AL_PITCH, variance);
			alSourcef(sid, AL_GAIN, vol);
			alSourcePlay(sid);

			// AudioSources.push_back(sid);
		}
	
	}
}
