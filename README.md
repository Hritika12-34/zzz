# zzz
#cc 1
#Install Virtual box/VMware Workstation with different flavours of linux or windows OS on top of windows.
-virtualbox.org
-download
-windows host
-if fails install microsoft virtual c++ redistributable 2015-22
-restart and start virtualbox again

search: linux os for pc
-www.ubuntu.com/desktop
-download ubuntu desktop
-complete installation

open vitualbox:
-create new
-give name of os: Ubuntu/Windows
-version name
-ram and hard disk
-create new,attach iso file, select from downloads
-click on start
-installation screen will popup

install os in virtualbox:
for ubuntu:
-click install ubuntu
-set username and password

for windows:
-click install
-custom install
-create partition and proceed

done

#cc 2
#Installation and configure Google App Engine. Create hello world app and other simple web applications using python.
#search npackd.org- download GAE
open:
-open python.org
-install python 2.7.9
-Windows x86-64 MSI Installer
-Complete installation

open GAE:
-open edit
-preferences: .exe(python 27)
-app engine sdk: (program files->google->gae
-click ok

-open file:
-create new app
-name
-parent directory: create folder on desktop uski path de
-runtime: python 2.7.
-port:8080
-admin:8000

open run

check files

open browser, search localhost:8080, open localhost, hello world dikegaa

#cc- 3
#Create a simple MapReduce program for word count analysis.
#mapper
# Mapper function
def mapper(text):
    words = text.split()
    mapped = []
    for word in words:
        mapped.append((word.lower(), 1))  # (word, 1)
    return mapped
    
# Reducer function
def reducer(mapped_data):
    word_count = {}
    for word, count in mapped_data:
        if word in word_count:
            word_count[word] += count
        else:
            word_count[word] = count
    return word_count
# Input Text
text = "MapReduce is simple. MapReduce is powerful."

# Step 1: Map
mapped_data = mapper(text)

# Step 2: Shuffle and Sort

# Step 3: Reduce
word_count = reducer(mapped_data)

# Step 4: Display Output
for word, count in word_count.items():
    print(f"{word}: {count}")



