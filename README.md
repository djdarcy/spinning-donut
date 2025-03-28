﻿# Spinning Donut 🍩

![Donut Status](https://img.shields.io/badge/donut-spinning-brightgreen) ![Bugs](https://img.shields.io/badge/bugs-yes-red) ![Donut Type](https://img.shields.io/badge/donut-ascii%20flavored-orange)

Welcome to the spinniest piece of ASCII art you'll ever see. Inspired by that [legendary video](https://youtu.be/T8B9U3JK9do) of the Russian coder caught in an altercation mid-hack, this project is an homage to both [retro coding](https://www.youtube.com/watch?v=VENFVhQqGls) and the beloved [demo scene](https://scene.org/). 🤘

![l337donut.gif](memes/l337donut.gif)

## What Is It?

A self-contained C program that renders a 3D spinning donut in your terminal! Sure, it's just ASCII characters and [math](https://www.a1k0n.net/2011/07/20/donut-math.html), but it's a party on your screen.

## How to Build

### Using GCC (Linux/macOS/WSL)
1. Open your terminal and navigate to the repo directory.

2. Compile & run:
   ```bash
   make && ./donut
   ```

### Using cl.exe (Windows)
1. Open the *Developer Command Prompt for Visual Studio*.
2. Navigate to the repo folder:
   ```cmd
   cd path\to\repo
   ```
3. Build with:
   ```cmd
   build.bat
   ```
   or manually:
   ```cmd
   cl /O2 donut.c
   ```
4. Run:
   ```cmd
   donut.exe
   ```

### One-Liner to Set CMD.exe Window Size
If CMD.exe is cutting off the donut, run the `.\tools\setsize.cmd` script, or copy and paste this into the *Run* dialog (Win+R) or a terminal:
```cmd
cmd /k mode con: cols=80 lines=25 & donut.exe
```
This ensures the console is sized correctly before launching the spinning masterpiece.

---

## Want to torment your neighbors?

**Bonus Idea: Add Sound!**

Why not make the donut program play a *beep* sound every time it spins? Modify `donut.c` to include:

```c 
#include <windows.h>  // Windows beep
Beep(500, 50); // Frequency 500Hz, Duration 50ms
```

For Linux/macOS, use:

```c
system("echo -e '\a'");
```

💡 *This will make the donut \*bloop\* as it spins, creating a cursed ASMR experience.*

## What else is here?

- **[CHANGELOG.md](CHANGELOG.md)** - Because even meme projects need version history.
- **[memes/](memes/) folder**: A collection of memes inspired by that epic coding moment.
- **[tools/](tools/) folder**: Contains a tool to convert MP4s to GIFs using ffmpeg because why not?
- **[tools/setsize.cmd](tools/setsize.cmd)** - A script to auto-set the correct CMD.exe dimensions.

## Contributing

Have a twist for the donut? Open a pull request! Let's make this donut spin harder, better, faster, stronger.

[![Harder, better, faster, strong, ever after, work is over](https://i.ytimg.com/vi_webp/gAjR4_CbPpQ/hqdefault.webp)](https://www.youtube.com/watch?v=gAjR4_CbPpQ)

## License

This project is released under the MIT License. Enjoy the spin, share the fun, and don’t take life (or your terminal output) too seriously!
