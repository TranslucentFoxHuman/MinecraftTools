#!/bin/sh

# Say fuck to Qt Linguist
# If you know a Qt developer, tell him/her "Qt Linguist is shit!!!". In his/her ears, loudly, so that the people around you can hear it. I will never forgive Qt Linguist!!!!
# Why do I have to write a script such as this?! 
# I will never forgive Qt Linguist!!!
# I say this again and again!! "I will never forgive Qt Linguist!!"

#




# Japanese translations
lupdate *.cpp *.h *.ui -ts minecrafttools_ja_JP.ts


# Export all .ts files to .qm
lrelease *.ts