#include "Sound.h"
#include <Windows.h>
#pragma comment(lib, "winmm.lib")

static void PlayWav(const char* file)
{
    PlaySoundA(file, NULL, SND_FILENAME | SND_ASYNC);
}

void Sound::StopAll() {
    PlaySoundA(NULL, NULL, 0);
}


void Sound::PlayKeyMusic() { PlayWav("open.wav"); }
void Sound::PlaySelect() { PlayWav("flippingbook.wav"); }
void Sound::PlayError() { PlayWav("error.wav"); }
void Sound::PlayStart() { PlayWav("equip.wav"); }
void Sound::PlayExit() { PlayWav("flippingbook.wav"); }
void Sound::PlayerWalk(){PlayWav("Walking.wav"); }
void Sound::PlayDoor() { PlayWav("door.wav"); }
void Sound::PlaySuitcase() { PlayWav("unholster.wav"); }
