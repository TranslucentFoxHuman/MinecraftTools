# MinecraftTools
Copyright (C) 2025 TlFoxHuman (TranslucentFoxHuman, 半狐, 半透明狐人間)

# Overview
This is a simple app which has various tools for playing Minecraft.  
This application was developed to make playing Minecraft - which the author started as a way to kill time — more convenient, and additionally as a way for the author to kill more time. Because it was made while killing time, it does not have many features.

Currently it includes the following features:
- Coordinate converter
- Search on the Minecraft Wiki
- Mob Generator
- Memo

# Features
## Coordinate
This tool converts coordinates between the Overworld and the Nether. Just enter numeric values in the input fields for the X and Y coordinates.

## Wiki
This tool opens the Minecraft Wiki or searches for pages on the Minecraft Wiki. That's all. If your environment language is English it will open the English site; if your environment language is Japanese it will open the Japanese site.

## Mob Generator
Generates commands to summon mobs. Currently it can summon horses and villagers. Each has customizable options — for example, for horses you can change health and speed, and for villagers you can change profession and clothing. There are other customizable options as well.  
Press the "Generate" button at the bottom to create the command. Paste that command into Minecraft's chat to use it.

## Memo
A simple memo page. It has no functionality other than writing plain text. Notes are not saved, so this is truly for temporary notes only.

# License
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.  
This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.  
You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.

# Development
## Which should I use: "CMakeLists.txt" or "minecrafttools.pro"?
These build files are separated depending on the platform you want to build for.  
Normal development is done using CMakeLists.txt. Use this for desktop platforms such as GNU/Linux, macOS, and Windows.  
For mobile platforms such as Android, due to bugs (probably) or missing features in Qt, you cannot build with CMake. Use minecrafttools.pro to build for mobile platforms.

## Desktop build
On GNU/Linux you can build like this:
```
mkdir build
cd build
cmake ..
make -j$(nproc)
sudo make install #Optional
```
For Windows, macOS, and other platforms, please read the Qt documentation for building on each respective platform.

## Android build
Only the following Qt versions are currently supported for Android builds:
- 5.15.2
- 6.2.4

### Why does this software support old versions of Qt?
This is because of bugs or missing features in Qt.  
First I tried building with the latest Qt 6.9.x. The build itself succeeded, but it was extremely unstable and not usable. Are the Qt Group serious about charging for this? It was too crazy. Thinking that this might be used in automotive software made me uneasy, so I gave up on the newest Qt and went to sleep that day — praying that Qt wouldn't cause more accidents.  
Next I tried the latest LTS 6.8.x. It was stable enough to use, but the menu bar was missing, which meant losing access to some functions.  
Therefore I used 5.15.x, which I had tried long ago for Android builds and which worked without problems. It required Java 8, but it worked well. However, because it depended on Java 8, some Android tools did not work and features such as automatic APK signing inside Qt Creator could not be used.  
There were so many issues that I searched the Internet and found information that 6.2.x is relatively stable, so I used 6.2.x. Everything worked!  
For these reasons this software supports only somewhat older versions of Qt. Don't worry — enable the "Archive" option in the components selection screen of the Qt Installer and you can install these versions!

## How to build for Android
Below are build steps for Qt 6.2.4, which can be used without particularly troublesome settings.  
Note: I am not very familiar with building Android applications from the command line, so I use Qt Creator to build. The following describes that procedure. If you prefer to build from the command line, please research that yourself :)

### Requirements
- Java 17 (on Ubuntu Java 21 can also be used, but Java 21 fails the build)
- Qt 6.2.4
- Qt Creator
- Android SDK configured for Qt 6.2.4 in Qt Creator

Open this project's .pro file in Qt Creator and enable the kit for your preferred architecture. Then press the build button at the bottom left — that's all!