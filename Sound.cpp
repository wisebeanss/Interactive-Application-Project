#include "Sound.h"
#include <Windows.h>
#include <mmsystem.h>
#include <string>
#include <iostream>
#pragma comment(lib, "winmm.lib")
using namespace std;

static void PlayBgmLoop(const char* audioFile)
{
    PlaySoundA(audioFile, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
// Play sound effect using MCI (doesn't interrupt background music)
static void PlayWavSFX(const char* audioFile)
{
    // Close any previously opened sound effect channel
    mciSendStringA("close mysfx", NULL, 0, NULL);

    // Open the audio file and assign to the "mysfx" channel
    string openCmd = string("open \"") + audioFile + "\" alias mysfx";

    // If file opened successfully, play the sound once
    if (mciSendStringA(openCmd.c_str(), NULL, 0, NULL) == 0) {
        mciSendStringA("play mysfx", NULL, 0, NULL);
    }
}
void PlayWavSFXAsync(const char* audioFile) {
    PlaySoundA(audioFile, NULL, SND_FILENAME | SND_ASYNC);
}
// Stop/close all the Bgm and sounds
void Sound::StopAll()
{
    PlaySoundA(NULL, NULL, 0); 
    mciSendStringA("stop mysfx", NULL, 0, NULL);
    mciSendStringA("close mysfx", NULL, 0, NULL);

}

// ========== ALL SOUNDS ==========
void Sound::Background() { PlayBgmLoop("background.wav"); }
void Sound::Manumusic() { PlayBgmLoop("Manu.wav"); }
void Sound::PlayKeyMusic() { PlayWavSFX("open.wav"); }
void Sound::PlaySelect() { PlayWavSFX("flippingbook.wav"); }
void Sound::PlayError() { PlayWavSFX("Error.wav"); }
void Sound::PlayStart() { PlayWavSFXAsync("equip.wav"); }

void Sound::PlayExit() { PlayWavSFX("Exit.wav"); }
void Sound::PlayerWalk() { PlayWavSFX("Walking.wav"); }

void Sound::PlayDoor() { PlayWavSFX("door.wav"); }
void Sound::PlayKnock() { PlayWavSFX("Doorhandle.wav"); }
void Sound::PlaySuitcase() { PlayWavSFX("unholster.wav"); }
void Sound::clock() { PlayWavSFX("Clock.wav"); }
void Sound::Playmirror() { PlayWavSFX("Mirror.wav"); }
void Sound::PickUp() { PlayWavSFX("PickUp.wav"); }
void Sound::PlayPhone() { PlayWavSFX("Phone.wav"); }
void Sound::Locker() { PlayWavSFX("Unlocked.wav"); }
void Sound::Ending1() { PlayWavSFX("Ending1.wav"); }
void Sound::Ending2() { PlayWavSFX("Ending3.wav"); }
void Sound::Ending3() { PlayWavSFX("Ending3.wav"); }