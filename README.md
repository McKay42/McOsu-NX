# McOsu NX

**WARNING: Use HBL takeover or NSP HBL to launch, or you WILL run out of memory and crash!**

**[DOWNLOAD > https://github.com/McKay42/McOsu-NX/releases](https://github.com/McKay42/McOsu-NX/releases)**

**Discord** (Feedback, Requests, Bug reports, etc.): https://discord.gg/3UQnt7X

This repository is for the **Nintendo Switch** port.  
For the game code and Desktop version see https://github.com/McKay42/McOsu/

An unofficial open-source client for [osu!](https://osu.ppy.sh) beatmaps, with the main focus on making practicing easier and customizing gameplay.

Runs on McEngine: [https://github.com/McKay42/McEngine](https://github.com/McKay42/McEngine)

## How to install:
1. Download the newest zip file from the releases page
2. Merge the contents of the zip file with your microSD card (do **NOT** change any folder/file structures/names!)
3. Launch [HBL via takeover](https://switchgui.de/switch-guide/user_guide/sysnand/launching_cfw/#launching-the-homebrew-menu) or [HBL via the NSP version](https://gbatemp.net/threads/homebrew-menu-loader-legal-nsp.518433/) (to get full RAM access, which this game requires), and start McOsu

## How to use:
* NOTE: You don't have to create any folder structures, everything is already prepared. Follow the guide on extracting beatmaps/skins below, and simply put them into `/switch/McOsu/Songs/` or `/switch/McOsu/Skins/` on your microSD card. Default beatmaps are already included, so just follow their structure.

* How to add beatmaps/skins: https://steamcommunity.com/sharedfiles/filedetails/?id=880768265

* FAQ: https://steamcommunity.com/app/607260/discussions/0/1620599015885400990/

* The game will give you a big fat warning on the main menu if it doesn't have access to enough memory (< 1 GB).

* At least on my system, if you still launch HBL via the Album applet, then only ~400 MB out of 4 GB are available, and some of that is already used up. (This might not even be a problem anymore with newer Atmosphere/ReiNX/etc. versions.)

* I have only tested this on firmware 5.1, with a pretty old SD setup and RajNX (which is no longer maintained), but never change a running system you know.

* If you get audio crackling after minimizing the game or going into sleep mode: To fix it, Go to Options > Audio > "Restart SoundEngine (fix crackling)"

* If you are playing beatmaps with a lot of sliders visible at the same time, and consistently getting less than 60 fps, improve performance by enabling Options > Skin > "Use slidergradient.png"

* If you get stuck at 0% loading forever, then the resource loader thread could not be created. Try restarting the game, HBL, and your system, in that order. This has only happened to me once, so it shouldn't be a problem.

* All speed changing mods are unavailable (DT/HT/DC/NC, Speed/BPM Multiplier, Timewarp) because the audio library does not support varying playback speed (yet).

## Screenshots:
![controls](/screenshots/controls.png?raw=true)
![screenshot1](/screenshots/screen1.png?raw=true)
![screenshot2](/screenshots/screen2.png?raw=true)
![screenshot3](/screenshots/screen3.png?raw=true)
![screenshot4](/screenshots/screen4.png?raw=true)
![screenshot5](/screenshots/screen5.png?raw=true)

## How to compile:
* McOsu-NX is a delta repository, i.e. everything you need in addition to the engine code and game code

* I'm using my own custom build of SDL2 and SDL2 Mixer to massively decrease audio latency and support a few other necessary features like scrubbing

* SDL2 audio uses `audout` instead of `audren` (i.e. [this is very bad for rhythm games](https://github.com/devkitPro/SDL/pull/31/files#diff-fa4ab70fa825f9880b736aed35fd4f2a))

* SDL2 Mixer includes Ext (`SDL_mixer_ext.h`) functionality

* Just overwrite your devkitpro portlib content temporarily for compiling

## Skin Credits:
- ffffffffffffffffff - "- Jaret - Mish Mosh"
- irrlux - "Talrava XIV"
- HazrdMC - "Phaze"
- Redon - "Aesthetic 1.3"
- DarkSlayer000 - "xXx_SampleSkin_xXx v1.3"
- Inori - "Stepmania"
- taikuta - "Murakumo"
- _Easy_ - "Burning_Crow V2"
- Icomoon
- Freepik
