## Programozási környezet

### Windows parancssor alapok

[Tutorial](https://www.digitalcitizen.life/command-prompt-how-use-basic-commands) / [Referencia](https://docs.microsoft.com/en-us/windows-server/administration/windows-commands/windows-commands)

 - `dir`: mappa tartalmának kilistázása
 - `cd`: "change dir", mappa váltás
 - `copy`: fájl másolása
 - `ren`: fájl átnevezése
 - `del`: fájl törlése
 - `mkdir`: "make dir", mappa létrehozása
 - `rd`: "remove dir", mappa törlése
 
 ### Fordítóprogramok
 
 Linux, MacOS:
  - [Clang](https://clang.llvm.org/) (nyílt forráskódú)
     - modern, kitűnő hibaüzenetek
  - [GCC](https://gcc.gnu.org/) (nyílt forráskódú)
     - legelterjedtebb
     - Windowson a [MinGW](http://www.mingw.org/) vagy a [CygWin](http://www.cygwin.com/) keretrendszereken keresztül használható ([különbségek](https://stackoverflow.com/a/792142))
 
 Windows:
  - [MSVC](https://blogs.msdn.microsoft.com/vcblog/2017/03/07/msvc-the-best-choice-for-windows/) (zárt forráskódú)
  
 ### IDE (Integrated Development Environment)
 
 IDE = szövegszerkesztő + fordítóprogram + extrák.
 
Tehát funkcionálisan ugyanaz, mint amikor Notepad++-ban szerkeszted a szöveget, és a parancssorban `g++`-szal fordítod, csak nagyobb programok esetén kényelmesebb.

**Otthon és órán bármivel dolgozhattok, de vizsgán le kell tudnotok fordítani a programotokat a parancssorban.**

Általában egy IDE megkeresi az elérhető fordítókat a gépeden (amik tipikusan a fenti 3 közül kerülnek ki), de sokszor neked kell őket installálni és beállítani. Ez esetben Google a barátotok.

Én kezdetnek a [Visual Studio Code](https://code.visualstudio.com/)-ot ajánlom. Komolyabb projektekhez ezután a legjobb választás a [Visual Studio Community](https://visualstudio.microsoft.com/vs/community/) (elég nagy program), vagy a [CLion](https://www.jetbrains.com/clion/) (diák licensszel).
  
 ### Fordítóprogram beszerzése
 
Órán a GCC C++ fordítóját, a `g++`-t használjuk, MinGW-n keresztül. Az alábbiakban az alap MinGW csomag installálásához szükséges lépéseket olvashatjátok el, de használhattok egyéb MinGW disztribúciót is. Ilyen pl. [Stephan T. Lavavej distroja](https://nuwen.net/mingw.html), amit csak ki kell csomagolni, és számos egyéb hasznos eszközt is tartalmaz. (Sőt, a legegyszerűbb Linuxon fejleszteni, ahol a szokásos parancssori eszközök és a `g++` mind adottak.)

 Nyissunk egy Command Promptot.
 
 ```
 C:\Users\rekan>g++
 'g++' is not recognized as an internal or external command,
 operable program or batch file.
 ```
  
Ha nem érhető el a `g++`, töltsd le a MinGW-t [innen](https://osdn.net/projects/mingw/downloads/68260/mingw-get-setup.exe/). Kattintgasd és várd végig addig, amíg be nem jön a MinGW Installation Manager. Jelöld be a `developer-toolkit`, `base`, `gcc-g++` tartalmú csomagokat (`Mark for Installation`), majd `Installation` >> `Apply Changes`.

Ha minden jól ment, a `g++` ezután elérhető a `C:\MinGW\bin\g++` útvonal alatt. Ellenőrizzük:

```
C:\Users\rekan>C:\MinGW\bin\g++
g++: fatal error: no input files
compilation terminated.
```

#### Elérés egyszerűsítése

Ha nem akarod minden alkalommal begépelni az egész útvonalat, hozzáadhatod a `g++`-t tartalmazó mappát a `PATH` környezeti változóhoz.
Először nézzük meg a `PATH` aktuális tartalmát:

```
C:\Users\rekan>echo %PATH%
C:\Program Files\Microsoft MPI\Bin\;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files\Git\cmd;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\WINDOWS\System32\OpenSSH\;C:\Program Files\dotnet\;C:\Program Files (x86)\Skype\Phone\;C:\Program Files\NVIDIA Corporation\NVIDIA NvDLISR;C:\Users\rekan\AppData\Local\Microsoft\WindowsApps;;C:\Program Files\Microsoft VS Code\bin 
```

Ha véletlenül elírnánk a következő parancsot, ezt kellene bele visszarakni.   
Adjuk hozzá a `g++` elérési útvonalát:

```
C:\Users\rekan>set PATH=C:\MinGW\bin;%PATH%

C:\Users\rekan>echo %PATH%
C:\MinGW\bin;C:\Program Files\Microsoft MPI\Bin\;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files\Git\cmd;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\WINDOWS\System32\OpenSSH\;C:\Program Files\dotnet\;C:\Program Files (x86)\Skype\Phone\;C:\Program Files\NVIDIA Corporation\NVIDIA NvDLISR;C:\Users\rekan\AppData\Local\Microsoft\WindowsApps;;C:\Program Files\Microsoft VS Code\bin

C:\Users\rekan>g++
g++: fatal error: no input files
compilation terminated.                                                          
```
