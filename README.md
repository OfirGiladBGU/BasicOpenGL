# Basic OpenGL


## How to install "make" command and C/C++ compilers:


### For Windows (make):


#### Option 1 (Install with `Chocolatey`):

1. Install `Chocolatey` from following website: \
   https://chocolatey.org/install

2. After finishing the installation intall `make` using the following command on the CMD (Run as adimistrator):
   ```
   choco install make
   ```


#### Option 2 (Install with `MSYS2`):

1. Install `MSYS2` from the following website: \
   https://www.msys2.org/

2. Open `MSYS2` and intall `make` using the following command (on the opened console):
   ```
   pacman -S make
   ```


### For Windows (C/C++ compilers):

1. Go to the following website: \
   https://code.visualstudio.com/docs/cpp/config-mingw

2. Follow the guide on how to install the C/C++ compilers and validate that they are installed by using the following commands on the CMD:
   ```
   gcc --version
   g++ --version
   ```


### For Windows (Enabling FFTW - Fastest Fourier Transform in the West):

**Note:** Under the folder: `lib/windows` there are several files with the name: `libfftw3`. \
In case that `make` fails to compile with them:

1. Delete all the files with the `.exp` and `.lib` extentions that contatin the name: `libfftw3`.

2. Make sure that the command `lib` in the CMD is working. \
   If not, add to your computer Environment Variables, under `System variables > Path`, the following path: \
   Option 1:
   ```
   C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.44.35207\bin\Hostx64\x64
   ```
   Option 2:
   ```
   C:\Program Files (x86)\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.44.35207\bin\Hostx64\x64
   ```
   **Note:**
   - The path may differ a bit based on the installed Visual Studio Version.
   - See the following link for help: \
   https://stackoverflow.com/questions/5343932/lib-exe-visual-studio-generating-lib-files-from-dlls-and-def-files

3. Navigate with the CMD to the path `lib/windows` and run the following commands on the CMD:
   ```
   lib /def:libfftw3-3.def
   lib /def:libfftw3f-3.def
   ```


### For MacOS (make `+` C/C++ compilers):

1. Install `Xcode Command Line Tools` using the following command on the Terminal:
   ```
   xcode-select --install
   ```

2. (Optional) Install `brew` from the following website: \
   https://brew.sh/

3. (Optional) Install with `brew` the `GLFW` library using the following command on the Terminal:
   ```
   brew install glfw
   ```


### For MacOS (Enabling FFTW - Fastest Fourier Transform in the West):

1. Install `brew` from the following website: \
   https://brew.sh/

1. Install `fftw` using the following command on the Terminal:
   ```
   brew install fftw
   ```


## For Linux (make `+` C/C++ compilers):

1. (Optional) Update the Linux OS using the following command on the Terminal:
   ```
   sudo apt update
   ```

2. Install `g++` using the following command on the Terminal:
   ```
   sudo apt install build-essential g++
   ```

3. Install `OpenGL` and `GLFW` using the following command on the Terminal:
   ```
   sudo apt install libgl-dev libglfw3-dev libxi-dev
   ```


### For Linux (Enabling FFTW - Fastest Fourier Transform in the West):

1. Install `fftw` using the following command on the Terminal:
   ```
   sudo apt install libfftw3-dev
   sudo apt install libfftw3-single3
   ```


## How to compile and run the OpenGL Engine using the Makefile:


### Using the CMD/Terminal:

1. Open the CMD/Terminal.

2. Navigate to the project folder using `cd` commands.

3. Run the following command:
   ```
   make
   ```

4. Run the following commands:
   ```
   cd bin
   ./main
   ```


### Using Visual Studio Code:

1. Download Visual Studio Code from: \
   https://code.visualstudio.com/download

2. Download the `C/C++ Extension Pack` from the Visual Studio Code Extensions or from: \
   https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack

3. Download the `Makefile Tools Extension` from the Visual Studio Code Extensions or from: \
   https://marketplace.visualstudio.com/items?itemName=ms-vscode.makefile-tools

4. Configure the `Makefile Tools Extension` to compile the engine: using the available [Makefile](Makefile):

   1. Edit the `Makefile` option, and set `The path to the makefile of the project` as: `Makefile`.

   2. Click on the `...` button near the `Play` button, and then choose: `Makefile:Configure`.

   3. Edit the `Lunch target` option, and choose the first option: `main()`.

   4. Click on the `Play` button and validate that the program compiles and runs successfully.

`Notice:` With this tool you can run the OpenGL in Debugging mode as well.


## MacOS known issue with "libglfw.3.dylib" file:

The MacOS tends to block the file: "libglfw.3.dylib" which is crucial for running the OpenGL Engine. 
To remove the block, open the MacOS "Settings", go to "Privacy & Security", scroll down until you find the "libglfw.3.dylib" and choose to enable permission for it.


## Useful guides for building the OpenGL Engine:

- For Windows: \
  https://www.youtube.com/watch?v=hRInLNR9iRg

- For MacOS: \
  https://www.youtube.com/watch?v=7-dL6a5_B3I

- For Linux: \
  https://www.youtube.com/watch?v=JxDLGHil-Cw


## Useful YouTube guides:

- The Cherno: \
  https://www.youtube.com/watch?v=W3gAzLwfIP0&list=PLlrATfBNZ98foTJPJ_Ev03o2oq3-GGOS2

- Victor Gordan: \
  https://www.youtube.com/watch?v=XpBGwZNyUh0&list=PLPaoO-vpZnumdcb4tZc4x5Q-v7CkrQ6M-


## Library sources:

- GLFW: \
  https://www.glfw.org/

- GLAD: \
  https://glad.dav1d.de/

- GLEW (Not used, But works similar to GLAD): \
  https://glew.sourceforge.net/

- stb: \
  https://github.com/nothings/stb

- glm: \
  https://github.com/g-truc/glm/releases/tag/1.0.1

- fftw: \
  https://www.fftw.org/download.html
