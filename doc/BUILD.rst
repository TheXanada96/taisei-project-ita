Taisei Project - opzioni di build
==============================

Questo è destinato a chiunque cerchi di costruire Taisei per uno qualsiasi dei suoi supporti
sistemi operativi, inclusi Linux, macOS, Windows, Emscripten, Switch e
altri.

.. contents::

Verifica del codice
-----------------

Innanzitutto, dovrai effettuare il checkout del repository. Puoi farlo con il
a seguire:

.. code:: sh

   git clone --recurse-submodules https://github.com/taisei-project/taisei

Il flag ``--recurse-submodules`` è assolutamente necessario, altrimenti Taisei non lo farà
build, poiché mancheranno molte delle dipendenze di cui ha bisogno per essere compilato. Se
lo ometti accidentalmente durante il checkout, puoi risolverlo con:

.. code:: sh

   cd taisei/
   git submodules update --init --recursive

Dipendenze
------------

Dipendenze in fase di compilazione
"""""""""""""""""""""""

-  ``gcc`` or ``clang``
-  meson >= 0.53.0 (0.56.2 recommended)
-  Python >= 3.6
-  `python-zstandard <https://github.com/indygreg/python-zstandard>`__ >= 0.11.1
-  `python-docutils <https://pypi.org/project/docutils/>`__ (facoltativo, per la generazione della documentazione)

Dipendenze in fase di esecuzione
"""""""""""""""""""""

Requisiti
''''''''

-  OpenGL >= 3.3, or OpenGL ES >= 3.0
-  SDL2 >= 2.0.10
-  cglm >= 0.7.8
-  libpng >= 1.5.0
-  libwebpdecoder >= 0.5 or libwebp >= 0.5
-  libzip >= 1.5.0 (>= 1.7.0 recommended)
-  libzstd >= 1.4.0
-  freetype2
-  opusfile
-  zlib

Opzionale
''''''''

-  SPIRV-Cross >= 2019-03-22 (for OpenGL ES backends)
-  libshaderc (for OpenGL ES backends)
-  `ANGLE <https://github.com/google/angle>`__ (useful for platforms with
   flaky/non-existent OpenGL support, such as Windows)
-  GameMode headers (Linux only; for automatic
   `GameMode <https://github.com/FeralInteractive/gamemode>`__ integration)
-  OpenSSL >= 1.1.0 or LibreSSL >= 2.7.0 (for a better SHA-256 implementation)


Dipendenze integrate e di sistema
""""""""""""""""""""""""""""""""

Grazie all'ampia gamma di piattaforme supportate da Taisei, forniamo meson
sottoprogetti per le sue dipendenze principali utilizzando il file
`Sistema di dipendenze Meson <https://mesonbuild.com/Wrap-dependency-system-manual.html>`__.
Questo per facilitare ambienti di compilazione coerenti, inclusi cross-build,
e per piattaforme più esoteriche come Emscripten.

Per comodità, ``meson`` rileverà quali pacchetti mancano nel tuo file
system e usa il suo sistema di dipendenza wrap per ottenere ciò che può. Affidarsi
su questo *non* è raccomandato nella maggior parte dei casi, e dovresti invece
affidati al gestore di pacchetti del tuo sistema operativo.

Per coerenza, tendiamo a rilasciare Taisei utilizzando esclusivamente pacchetti integrati.
Tuttavia, puoi anche utilizzare le dipendenze di sistema. C'è un compromesso in
coerenza e riproducibilità per velocità e facilità d'uso.

Questo è controllato tramite il flag ``--wrap-mode`` con ``meson``. (Di più
su quello dopo.)

Linux
'''''

Su una distribuzione basata su Ubuntu o Debian, quanto segue installerà il file obbligatorio
strumenti per costruire Taisei.

.. code:: sh

   apt update
   apt install meson cmake build-essential

Oltre a ciò, consulta l'elenco *Dipendenze* sopra. Molte distribuzioni
dipendenze di sistema in fase di compilazione del pacchetto con ``*-dev`` (es: ``libsdl2-dev``).
Cerca con il gestore pacchetti della tua distribuzione per installare le librerie corrette.

macOS
'''''

Su macOS, devi installare gli strumenti della riga di comando Xcode per creare Taisei
la piattaforma, poiché contiene intestazioni e strumenti per la creazione di app macOS native.

.. code:: sh

   xcode-select --install

Ci sono altri strumenti da riga di comando di cui avrai bisogno. Puoi acquisirli
utilizzando `Homebrew <https://brew.sh/>`__.

Segui le istruzioni per l'installazione di Homebrew, quindi installa quanto segue
Strumenti:

.. code:: sh

   brew install meson cmake pkg-config docutils pygments

È quindi possibile installare le dipendenze dall'elenco *Dipendenze*.

A partire dal 05-08-2021, **non** installare i seguenti pacchetti tramite
Homebrew, poiché le versioni disponibili non compilano correttamente contro Taisei.
Se riscontri errori misteriosi, assicurati che non siano installati.

-  ``spirv-tools``
-  ``spirv-cross``

.. code:: sh

   brew remove spirv-tools spirv-cross

Inoltre, se stai tentando di compilare su una versione precedente di macOS
(es: <10.12), SDL2 potrebbe non essere compilato correttamente su Homebrew (a partire dal 19-02-2019).
Lascia che ``meson`` estragga la versione corretta per te tramite sottoprogetti.

Puoi anche installare `create-dmg <https://github.com/create-dmg/create-dmg>`__
per pacchettizzare ``.dmg`` files, che abilita alcune opzioni aggiuntive come
posizionamento delle icone nel ``.dmg``.

Windows
'''''''

Taisei usa `mstorsjo/llvm-mingw <https://github.com/mstorsjo/llvm-mingw>`__ per
ottenere la compilazione incrociata per Windows. La Toolchain del compilatore C nativo di Microsoft
semplicemente non supporta i pacchetti di Taisei e ha bisogno di compilare correttamente, incluso
cose fondamentali come `complex numbers <https://en.wikipedia.org/wiki/Complex_number>`__.


Puoi usare anche ``llvm-mingw``, oppure puoi controllare se la tua distribuzione ne ha
Sono disponibili anche toolchain cross-compilatore ``mingw64``. Questo è solo quello
che funziona per noi.

Inoltre, puoi installare `nsis <https://nsis.sourceforge.io/Main_Page>`__
(>= 3.0) per pacchettizzare gli installer Windows ``.exe`` files. (Tuttavia, puoi
ancora pacchettizzare i file ``.zip`` per Windows su di esso.

Su macOS, dovresti probabilmente usare Docker e
`Docker container <https://hub.docker.com/r/mstorsjo/llvm-mingw/>`__ che
``llvm-mingw`` fornisce e installa ``nsis`` su di esso.

Un'altra opzione per i computer basati su Windows è sfruttare il sottosistema Linux.
`(WSL). <https://docs.microsoft.com/en-us/windows/wsl/install-win10>`__
per eseguire la compilazione incrociata su Windows utilizzando la loro immagine Ubuntu. Puoi anche potenzialmente
usa una toolchain ``mingw64`` direttamente su Windows, tuttavia non è supportata
o consigliato, poiché generalmente è più un problema che il suo valore.

Opzioni di compilazione
-------------

This is *not* an exhaustive list. You can see the full list of option using
``meson`` in the ``taisei`` directory.

.. code:: sh

   cd taisei/
   meson configure

Setup
"""""

The first command you'll need to run is ``setup``, which creates a directory
(in this case, ``taisei/build/``). It checks your system for various
dependencies and required tools, which should take about a minute on most
systems.

.. code:: sh

   # inside the taisei/ directory you cloned before
   meson setup build/

You can also have the ``setup`` command contain certain build options (seen
below). The following are an *example* and *not required* for getting Taisei
building.

.. code:: sh

   # enables Developer Mode and debugging symbols
   meson setup build/ -Ddeveloper=true -Dbuildtype=debug

You can then apply more build options later using ``meson configure`` (as seen
below). It will automatically reconfigure your build environment with the new
options without having to rebuild everything.

System/Vendored Dependencies (``--wrap-mode``)
""""""""""""""""""""""""""""""""""""""""""""""

See: `Meson Manual <https://mesonbuild.com/Wrap-dependency-system-manual.html>`__

* Default: ``default``
* Options: ``default``, ``nofallback``, ``forcefallback``, ...

This is a core ``meson`` flag that does quite a few things. Not all of them will
be covered here. Refer to the ``meson`` documentation linked above.

Generally, ``default`` will rely on system-installed libraries when available,
and download missing dependencies when necessary.

``forcefallback`` will force the use of wrapped dependencies whenever possible.
Recommended for release builds.

``nofallback`` disallows the use of wrapped dependencies whenever possible,
instead relying on system libraries. Useful for CI.

.. code:: sh

   # forces in-repo dependencies
   meson configure build/ --wrap-mode=forcefallback
   # disables in-repo repositories
   meson configure build/ --wrap-mode=nofallback

Relative Directory Install (``-Dinstall_relative``)
"""""""""""""""""""""""""""""""""""""""""""""""""""

* Default: ``true`` or ``false`` (platform-dependent)

``-Dinstall_relative`` is a special option that changes depending on the
platform build target.

It is set to ``true`` when building for macOS, Windows, Emscripten, and Switch.

It is set to ``false`` when building for Linux.

Install Prefix (``--prefix``)
"""""""""""""""""""""""""""""

* Default: ``/usr/local``

``--prefix`` installs the Taisei binary and content files to a path of your
choice on your filesystem.

On Linux without ``-Dinstall_relative`` enabled (i.e: ``false``), it should be
kept to its default ``/usr/local``. In general, don't touch it unless you need
to.

On other platforms, it will install all Taisei game files to the directory of
your choice.

.. code:: sh

   meson setup --prefix=/path/goes/here build/

Package Data (``-Dpackage_data``)
"""""""""""""""""""""""""""""""""

* Default: ``auto``
* Options: ``auto``, ``true``, ``false``

Packages game data into either a directory or a ``.zip`` depending on if
``-Denable_zip`` is ``true`` (see below).

.. code:: sh

   meson configure build/ -Dpackage_data=false

Enable ZIP Loading (``-Denable_zip``)
"""""""""""""""""""""""""""""""""""""

* Default: ``true```
* Options: ``true``, ``false``

Controls whether or not Taisei can load game data (textures, shaders, etc) from
``.zip`` files. Useful for distribution and packaging.

**NOTE:** Setting this to ``false`` automatically disables ``-Dpackage_data``.

.. code:: sh

   meson configure build/ -Denable_zip=false

In-Game Developer Options (``-Ddeveloper``)
"""""""""""""""""""""""""""""""""""""""""""

* Default: ``false``
* Options: ``true``, ``false``

For testing actual gameplay, you can set this option and it will enable cheats
and other 'fast-forward' options by the pressing keys defined in
``src/config.h``.

.. code:: sh

   meson configure build/ -Ddeveloper=true

Build Type (``-Dbuildtype``)
""""""""""""""""""""""""""""

* Default: ``release``
* Options: ``release``, ``debug``

Sets the type of build. ``debug`` enables several additional debugging features,
as well as reduced optimizations and more debugging symbols.

.. code:: sh

   meson configure build/ -Dbuildtype=debug

Assertions (``-Db_ndebug``)
"""""""""""""""""""""""""""

* Default: ``true``
* Options: ``true``, ``false``

The name of this flag is opposite of what you'd expect. Think of it as "Not
Debugging". It controls the ``NDEBUG`` declaration which is responsible for
deactivating ``assert()`` macros.

Setting to ``false`` will *enable* assertions (i.e: good for debugging).

Keep ``true`` during release.

.. code:: sh

   meson configure build/ -Db_ndebug=false

Strict Compiler Warnings (``-Dwerror``)
"""""""""""""""""""""""""""""""""""""""

* Default: ``false``
* Options: ``true``, ``false``

This option forces stricter checks against Taisei's codebase to ensure code
health, treating all ``Warnings`` as ``Errors`` in the code.

It's highly recommended to **enable** (i.e: ``true``) this whenever developing
for the engine. Sometimes, it's overly-pedantic, but much of the time, it
provides useful advice. (For example, it can detect potential null-pointer
exceptions that may not be obvious to the human eye.)

.. code:: sh

   meson configure build/ -Dwerror=true

Deprecation Warnings (``-Ddeprecation_warnings``)
"""""""""""""""""""""""""""""""""""""""""""""""""

* Default: ``default``
* Options: ``error``, ``no-error``, ``ignore``, ``default``

Sets deprecation warnings to either hard-fail (``error``), print as warnings but
not trigger full errors if ``-Dwerror=true`` (``no-error``), and otherwise
ignore them (``ignore``). ``default`` respects the ``-Dwerror`` setting.

Generally, ``no-error`` is the recommended default when using ``-Dwerror=true``.

.. code:: sh

   meson configure build/ -Ddeprecation_warnings=no-error


Debugging With Sanitizers (``-Db_sanitize``)
""""""""""""""""""""""""""""""""""""""""

This is useful for debugging memory management errors, leaks, and undefined behavior.
However, there is some additional setup required to use it.

.. code:: sh

   meson configure build/ -Db_sanitize=address,undefined

Depending on your platform, you may need to specify the specific library binary
to use to launch ASan appropriately. Using macOS as an example:

.. code:: sh

   export DYLD_INSERT_LIBRARIES=/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/12.0.5/lib/darwin/libclang_rt.asan_osx_dynamic.dylib

The ``../12.0.5/..`` in the path of ``DYLD_INSERT_LIBRARIES`` changes with each
version of Xcode. If it fails to launch for you, ensure that the version number
is correct by browsing to the parent directory of ``../clang``.

Then, you can launch Taisei's binary from the command line (using macOS as an
example):

.. code:: sh

   /path/to/Taisei.app/Contents/MacOS/Taisei

Further reading: `Sanitizers <https://github.com/google/sanitizers/wiki>`__

Link-Time Optimizations (``-Db_lto``)
"""""""""""""""""""""""""""""""""""""

* Default: ``true``
* Options: ``true``, ``false``

Link-time optimizations (LTO) increase build times, but also increase
performance. For quicker build times during development, you can disable it.
For release builds, this should be kept ``true``.

See: `Interprocedural Optimization <https://en.wikipedia.org/wiki/Interprocedural_optimization#WPO_and_LTO>`__

.. code:: sh

   meson configure build/ -Db_lto=false

Binary Striping (``-Dstrip``)
"""""""""""""""""""""""""""""

* Default: ``true``
* Options: ``true``, ``false``

This option prevents stripping of the `taisei` binary, providing a marginally
faster build time.

Keep this ``true`` during releases, but ``false`` during development, as it will
strip out useful debugging symbols.

.. code:: sh

   meson configure build/ -Db_strip=false

Rendering
"""""""""

Backends (``-Dr_gl*``)
''''''''''''''''''''''

* Default: ``false``
* Options: ``true``, ``false``

Enable or disable the various renderer backends for Taisei.

``-Dshader_transpiler`` is required for when OpenGL ES is used.

.. code:: sh

   # for GL 3.3 (default)
   meson configure build/ -Dr_gl33=true
   # for GL ES 3.0
   meson configure build/ -Dr_gles30=true
   # for GL ES 2.0 (not recommended)
   meson configure build/ -Dr_gles20=true

**NOTE:** GL ES 2.0 is *not recommended* as it is unsupported and may
not work correctly. However, if for some reason you still want to use it,
it requires a few extensions to be present on your system to function
correctly, most notably:

- ``OES_depth_texture`` or ``GL_ANGLE_depth_texture``
- ``OES_standard_derivatives``
- ``OES_vertex_array_object``
- ``EXT_frag_depth``
- ``EXT_instanced_arrays`` or ``ANGLE_instanced_arrays`` or
  ``NV_instanced_arrays``

Default Renderer (``-Dr_default``)
''''''''''''''''''''''''''''''''''

* Default: ``gl33``
* Options: ``gl33``, ``gles30``, ``gles20``, ``null``

Sets the default renderer to use when Taisei launches.

.. code:: sh

   # for GL 3.3 (default)
   meson configure build/ -Dr_default=gl33
   # for GL ES 3.0
   meson configure build/ -Dr_default=gles30
   # for GL ES 2.0 (not recommended)
   meson configure build/ -Dr_default=gles20

You can switch the renderer using the ``--renderer`` flag on the ``taisei``
binary. (i.e: ``taisei --renderer gl33``).

Shader Transpiler (``-Dshader_transpiler``)
'''''''''''''''''''''''''''''''''''''''''''

* Default: ``false``
* Options: ``true``, ``false``

For using OpenGL ES, the shader transpiler is necessary for converting Taisei's
shaders to a format usable by that driver.

.. code:: sh

   meson configure build/ -Dshader_transpiler=true

ANGLE
"""""

Building ANGLE (Optional)
'''''''''''''''''''''''''
`ANGLE <https://github.com/google/angle>`__ is Google's graphics translation
layer, intended for for Chromium. Taisei packages it with Windows builds to
workaround some bugs and performance issues with many Windows OpenGL drivers,
and it can be optionally packaged as as an experimental Metal renderer for
macOS.

You need to read
`this guide <https://github.com/google/angle/blob/master/doc/DevSetup.md>`__ and
set up Google's custom build system to get things going. However, the below
commands might help you compiling what you need from it when you have that all
set up.

.. code:: sh

   cd angle
   python ./scripts/bootstrap.py
   gclient sync
   gn gen out/x64 --args='is_debug=false dcheck_always_on=false target_cpu="x64"'
   ninja -C out/x64 libEGL libGLESv2

It will output two files to ``angle/out/x64``:

* ``libEGL.(*)``
* ``libGLESv2.(*)``

The file extension can be ``.dll`` for Windows, ``.dylib`` for macOS,
and ``.so`` for Linux.

Using ``-Dinstall_angle`` and ``-Dangle_lib*`` (see below), ``meson`` will copy
those files over into the package itself when running the packaging steps.

ANGLE Library Paths (``-Dangle_lib*``)
''''''''''''''''''''''''''''''''''''''

* Default: ``(null)``
* Options: ``/path/to/libGLESv2.{dll,dylib,so}``/``path/to/libEGL.{dll,dylib,so}``

``-Dangle_libgles`` and ``-Dangle_libegl`` provide the full paths to the ANGLE
libraries necessary for that engine.

Generally, both need to be supplied at the same time.

.. code:: sh

   # for macOS
   meson configure build/ -Dangle_libgles=/path/to/libGLESv2.dylib -Dangle_libegl=/path/to/libEGL.dylib
   # for Linux
   meson configure build/ -Dangle_libgles=/path/to/libGLESv2.so -Dangle_libegl=/path/to/libEGL.so
   # for Windows
   meson configure build/ -Dangle_libgles=/path/to/libGLESv2.dll -Dangle_libegl=/path/to/libEGL.dll

Install ANGLE (``-Dinstall_angle``)
'''''''''''''''''''''''''''''''''''

* Default: ``false``
* Options: ``true``, ``false``

Installs the ANGLE libraries supplied above through ``-Dangle_lib*``.

Generally recommended when packaging ANGLE for distribution.

.. code:: sh

   meson configure build/ -Dinstall_angle=true

