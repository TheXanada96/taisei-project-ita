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

Impostare
"""""

Il primo comando che dovrai eseguire è ``setup``, che crea una directory
(in questo caso, ``taisei/build/``). Controlla il tuo sistema per vari
dipendenze e strumenti richiesti, che dovrebbero richiedere circa un minuto al massimo
sistemi.

.. codice:: sh

   # all'interno della directory taisei/ che hai clonato in precedenza
   costruzione configurazione mesone/

Puoi anche fare in modo che il comando ``setup`` contenga alcune opzioni di compilazione (viste
sotto). I seguenti sono un *esempio* e *non richiesto* per ottenere Taisei
edificio.

.. codice:: sh

   # abilita la modalità sviluppatore e i simboli di debug
   meson setup build/ -Ddeveloper=true -Dbuildtype=debug

Puoi quindi applicare più opzioni di compilazione in un secondo momento usando ``meson configure`` (come visto
sotto). Riconfigurerà automaticamente il tuo ambiente di compilazione con il nuovo
opzioni senza dover ricostruire tutto.

Dipendenze sistema/fornitore (``--wrap-mode``)
""""""""""""""""""""""""""""""""""""""""""""""

Vedere: `Meson Manual <https://mesonbuild.com/Wrap-dependency-system-manual.html>`__

* Predefinito: ``predefinito``
* Opzioni: ``default``, ``nofallback``, ``forcefallback``, ...

Questo è un flag ``meson`` di base che fa un bel po' di cose. Non tutti lo faranno
essere coperto qui. Fare riferimento alla documentazione del ``mesone`` collegata sopra.

Generalmente, ``default`` si baserà sulle librerie installate dal sistema quando disponibili,
e scarica le dipendenze mancanti quando necessario.

``forcefallback`` forzerà l'uso di dipendenze incapsulate quando possibile.
Consigliato per build di rilascio.

``nofallback`` non consente l'uso di dipendenze incapsulate quando possibile,
affidandosi invece alle librerie di sistema. Utile per CI.

.. codice:: sh

   # forza le dipendenze in-repo
   meson configure build/ --wrap-mode=forcefallback
   # disabilita i repository in-repo
   meson configure build/ --wrap-mode=nofallback

Installazione directory relativa (``-Dinstall_relative``)
"""""""""""""""""""""""""""""""""""""""""""""""""" "

* Predefinito: ``true`` o ``false`` (dipende dalla piattaforma)

``-Dinstall_relative`` è un'opzione speciale che cambia a seconda del file
obiettivo di costruzione della piattaforma.

È impostato su ``true`` durante la compilazione per macOS, Windows, Emscripten e Switch.

È impostato su ``false`` durante la compilazione per Linux.

Prefisso di installazione (``--prefix``)
"""""""""""""""""""""""""""""

* Predefinito: ``/usr/local``

``--prefix`` installa i file binari e di contenuto di Taisei in un percorso del tuo
scelta sul tuo filesystem.

Su Linux senza ``-Dinstall_relative`` abilitato (cioè: ``false``), dovrebbe essere
mantenuto al suo valore predefinito ``/usr/local``. In generale, non toccarlo a meno che non sia necessario
A.

Su altre piattaforme, installerà tutti i file di gioco Taisei nella directory di
la tua scelta.

.. codice:: sh

   meson setup --prefix=/path/goes/here build/

Dati pacchetto (``-Dpackage_data``)
"""""""""""""""""""""""""""""""""

* Predefinito: ``auto``
* Opzioni: ``auto``, ``true``, ``false``

Impacchetta i dati di gioco in una directory o in un ``.zip`` a seconda di se
``-Denable_zip`` è ``true`` (vedi sotto).

.. codice:: sh

   meson configure build/ -Dpackage_data=false

Abilita caricamento ZIP (``-Denable_zip``)
"""""""""""""""""""""""""""""""""""""

* Predefinito: ``true```
* Opzioni: ``vero``, ``falso``

Controlla se Taisei può o meno caricare i dati di gioco (texture, shader, ecc.) da
File ``.zip``. Utile per la distribuzione e il confezionamento.

**NOTA:** l'impostazione su ``false`` disabilita automaticamente ``-Dpackage_data``.

.. codice:: sh

   meson configure build/ -Denable_zip=false

Opzioni sviluppatore in-game (``-Ddeveloper``)
""""""""""""""""""""""""""""""""""""""""""

* Predefinito: ``falso``
* Opzioni: ``vero``, ``falso``

Per testare il gameplay reale, puoi impostare questa opzione e abiliterà i cheat
e altre opzioni di "avanzamento rapido" premendo i tasti definiti in
``src/config.h``.

.. codice:: sh

   meson configure build/ -Ddeveloper=true

Tipo di build (``-Dbuildtype``)
""""""""""""""""""""""""""""

* Predefinito: ``rilascio``
* Opzioni: ``rilascio``, ``debug``

Imposta il tipo di build. ``debug`` abilita diverse funzionalità di debug aggiuntive,
così come ottimizzazioni ridotte e più simboli di debug.

.. codice:: sh

   meson configure build/ -Dbuildtype=debug

Asserzioni (``-Db_ndebug``)
"""""""""""""""""""""""""""

* Predefinito: ``true``
* Opzioni: ``vero``, ``falso``

Il nome di questa bandiera è l'opposto di quello che ti aspetteresti. Pensalo come "No
Debugging". Controlla la dichiarazione ``NDEBUG`` di cui è responsabile
disattivando le macro ``assert()``.

L'impostazione su ``false`` *abiliterà* le asserzioni (vale a dire: buono per il debug).

Mantieni ``true`` durante il rilascio.

.. codice:: sh

   meson configure build/ -Db_ndebug=false

Avvisi rigorosi del compilatore (``-Dwerror``)
"""""""""""""""""""""""""""""""""""""""

* Default: ``false``
* Options: ``true``, ``false``

Questa opzione impone controlli più rigorosi sulla base di codice di Taisei per garantire il codice
salute, trattando tutti gli ``Avvisi`` come ``Errori`` nel codice.

Si consiglia vivamente di **abilitare** (ovvero: ``true``) questo ogni volta che si sviluppa
per il motore. A volte è eccessivamente pedante, ma la maggior parte delle volte lo è
fornisce utili consigli. (Ad esempio, può rilevare potenziali puntatori nulli
eccezioni che potrebbero non essere evidenti all'occhio umano.)

.. code:: sh

   meson configure build/ -Dwerror=true

Avvisi di deprecazione (``-Ddeprecation_warnings``)
"""""""""""""""""""""""""""""""""""""""""""""""""

* Default: ``default``
* Options: ``error``, ``no-error``, ``ignore``, ``default``

Imposta gli avvisi di deprecazione su hard-fail (``error``), stampa come avvisi ma
non attivare errori completi se ``-Dwerror=true`` (``no-error``), e altrimenti
ignorali (``ignore``). ``default`` rispetta l'impostazione ``-Dwerror``.

Generalmente, ``no-error`` è l'impostazione predefinita consigliata quando si utilizza ``-Dwerror=true``.

.. code:: sh

   meson configure build/ -Ddeprecation_warnings=no-error


Debug con disinfettanti (``-Db_sanitize``)
""""""""""""""""""""""""""""""""""""""""

Ciò è utile per il debug di errori di gestione della memoria, perdite e comportamento non definito.
Tuttavia, sono necessarie alcune impostazioni aggiuntive per utilizzarlo.

.. codice:: sh

   meson configure build/ -Db_sanitize=indirizzo,non definito

A seconda della piattaforma, potrebbe essere necessario specificare il binario della libreria specifica
da utilizzare per avviare ASan in modo appropriato. Usando macOS come esempio:

.. codice:: sh

   export DYLD_INSERT_LIBRARIES=/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/12.0.5/lib/darwin/libclang_rt.asan_osx_dynamic.dylib

``../12.0.5/..`` nel percorso di ``DYLD_INSERT_LIBRARIES`` cambia a ogni
versione di Xcode. Se non si avvia per te, assicurati che il numero di versione
è corretto sfogliando la directory principale di ``../clang``.

Quindi, puoi avviare il file binario di Taisei dalla riga di comando (usando macOS come file
esempio):

.. codice:: sh

   /path/to/Taisei.app/Contents/MacOS/Taisei

Ulteriori letture: `Disinfettanti <https://github.com/google/sanitizers/wiki>`__

Ottimizzazioni del tempo di collegamento (``-Db_lto``)
"""""""""""""""""""""""""""""""""""""

* Predefinito: ``true``
* Opzioni: ``vero``, ``falso``

Le ottimizzazioni del tempo di collegamento (LTO) aumentano i tempi di compilazione, ma aumentano anche
prestazione. Per tempi di compilazione più rapidi durante lo sviluppo, puoi disabilitarlo.
Per le build di rilascio, questo dovrebbe essere mantenuto ``true``.

Vedere: `Ottimizzazione interprocedurale <https://en.wikipedia.org/wiki/Interprocedural_optimization#WPO_and_LTO>`__

.. codice:: sh

   meson configure build/ -Db_lto=false

Striping binario (``-Dstrip``)
"""""""""""""""""""""""""""""

* Predefinito: ``true``
* Opzioni: ``vero``, ``falso``

Questa opzione impedisce lo stripping del binario `taisei`, fornendo un valore marginale
tempi di costruzione più rapidi.

Mantieni questo ``vero`` durante i rilasci, ma ``falso`` durante lo sviluppo, come sarà
eliminare utili simboli di debug.

.. codice:: sh

   meson configure build/ -Db_strip=false

Rendering
"""""""""

Backend (``-Dr_gl*``)
'''''''''''''''''''''''

* Predefinito: ``falso``
* Opzioni: ``vero``, ``falso``

Abilita o disabilita i vari backend del renderer per Taisei.

``-Dshader_transpiler`` è necessario quando si usa OpenGL ES.

.. codice:: sh

   # per GL 3.3 (predefinito)
   meson configure build/ -Dr_gl33=true
   # per GL ES 3.0
   meson configure build/ -Dr_gles30=true
   # per GL ES 2.0 (non consigliato)
   meson configure build/ -Dr_gles20=true

**NOTA:** GL ES 2.0 *non è consigliato* in quanto non è supportato e potrebbe
non funziona correttamente. Tuttavia, se per qualche motivo desideri ancora utilizzarlo,
richiede che alcune estensioni siano presenti sul tuo sistema per funzionare
correttamente, in particolare:

- ``OES_depth_texture`` o ``GL_ANGLE_depth_texture``
- ``OES_standard_derivatives``
- ``OES_vertex_array_object``
- ``EXT_frag_depth``
- ``EXT_instanced_arrays`` o ``ANGLE_instanced_arrays`` o
  ``NV_instanced_arrays``

Rendering predefinito (``-Dr_default``)
'''''''''''''''''''''''''''''''''''

* Predefinito: ``gl33``
* Opzioni: ``gl33``, ``gles30``, ``gles20``, ``null``

Imposta il renderer predefinito da utilizzare all'avvio di Taisei.

.. codice:: sh

   # per GL 3.3 (predefinito)
   meson configure build/ -Dr_default=gl33
   # per GL ES 3.0
   meson configure build/ -Dr_default=gles30
   # per GL ES 2.0 (non consigliato)
   meson configure build/ -Dr_default=gles20

Puoi cambiare il renderer usando il flag ``--renderer`` sul ``taisei``
binario. (es: ``taisei --renderer gl33``).

Shader Transpiler (``-Dshader_transpiler``)
''''''''''''''''''''''''''''''''''''''''''''

* Predefinito: ``falso``
* Opzioni: ``vero``, ``falso``

Per utilizzare OpenGL ES, è necessario lo shader transpiler per la conversione di Taisei
shader in un formato utilizzabile da quel driver.

.. codice:: sh

   meson configure build/ -Dshader_transpiler=true

ANGOLO
"""""

Compilare ANGLE (Opzionale)
''''''''''''''''''''''''''
`ANGLE <https://github.com/google/angle>`__ è la traduzione grafica di Google
strato, destinato a Chromium. Taisei lo impacchetta con le build di Windows
risolvere alcuni bug e problemi di prestazioni con molti driver Windows OpenGL,
e può essere facoltativamente impacchettato come renderer Metal sperimentale per
Mac OS.

Devi leggere
`questa guida <https://github.com/google/angle/blob/master/doc/DevSetup.md>`__ e
imposta il sistema di build personalizzato di Google per far funzionare le cose. Tuttavia, il sotto
i comandi potrebbero aiutarti a compilare ciò di cui hai bisogno quando hai tutto
impostare.

.. codice:: sh

   angolo cd
   python ./scripts/bootstrap.py
   sincronizzazione client
   gn gen out/x64 --args='is_debug=false dcheck_always_on=false target_cpu="x64"'
   ninja -C out/x64 libEGL libGLESv2

Produrrà due file in ``angle/out/x64``:

* ``libEGL.(*)``
* ``libGLESv2.(*)``

L'estensione del file può essere ``.dll`` per Windows, ``.dylib`` per macOS,
e ``.so`` per Linux.

Usando ``-Dinstall_angle`` e ``-Dangle_lib*`` (vedi sotto), ``meson`` copierà
quei file nel pacchetto stesso durante l'esecuzione dei passaggi di creazione del pacchetto.

Percorsi libreria ANGLE (``-Dangle_lib*``)
'''''''''''''''''''''''''''''''''''''''

* Predefinito: ``(nullo)``
* Opzioni: ``/percorso/a/



ANGLE
"""""

Compilare ANGLE (Opzionale)
'''''''''''''''''''''''''
`ANGLE <https://github.com/google/angle>`__ è la traduzione grafica di Google
strato, destinato a Chromium. Taisei lo impacchetta con le build di Windows
risolvere alcuni bug e problemi di prestazioni con molti driver Windows OpenGL,
e può essere facoltativamente impacchettato come renderer Metal sperimentale per
Mac OS.

Devi leggere
`questa guida <https://github.com/google/angle/blob/master/doc/DevSetup.md>`__ e
imposta il sistema di build personalizzato di Google per far funzionare le cose. Tuttavia, il sotto
i comandi potrebbero aiutarti a compilare ciò di cui hai bisogno quando hai tutto
impostare.

.. codice:: sh

   angolo cd
   python ./scripts/bootstrap.py
   sincronizzazione client
   gn gen out/x64 --args='is_debug=false dcheck_always_on=false target_cpu="x64"'
   ninja -C out/x64 libEGL libGLESv2

Produrrà due file in ``angle/out/x64``:

* ``libEGL.(*)``
* ``libGLESv2.(*)``

L'estensione del file può essere ``.dll`` per Windows, ``.dylib`` per macOS,
e ``.so`` per Linux.

Usando ``-Dinstall_angle`` e ``-Dangle_lib*`` (vedi sotto), ``meson`` copierà
quei file nel pacchetto stesso durante l'esecuzione dei passaggi di creazione del pacchetto.

Percorsi libreria ANGLE (``-Dangle_lib*``)
'''''''''''''''''''''''''''''''''''''''

* Predefinito: ``(nullo)``
* Opzioni: ``/path/to/libGLESv2.{dll,dylib,so}``/``path/to/libEGL.{dll,dylib,so}``

``-Dangle_libgles`` e ``-Dangle_libgles`` forniscono i percorsi completi per ANGLE
librerie necessarie per quel motore.

In genere, entrambi devono essere forniti contemporaneamente.

.. codice:: sh

   # per macOS
   meson configure build/ -Dangle_libgles=/path/to/libGLESv2.dylib -Dangle_libgles=/path/to/libEGL.dylib
   # per Linux
   meson configure build/ -Dangle_libgles=/path/to/libGLESv2.so -Dangle_libgles=/path/to/libEGL.so
   # per Windows
   meson configure build/ -Dangle_libgles=/path/to/libGLESv2.dll -Dangle_libegl=/path/to/libEGL.dll

Installa ANGLE (``-Dinstall_angle``)
''''''''''''''''''''''''''''''''''''

* Predefinito: ``falso``
* Opzioni: ``vero``, ``falso``

Installa le librerie ANGLE fornite sopra tramite ``-Dangle_lib*``.

Generalmente consigliato quando si confeziona ANGLE per la distribuzione.

.. codice:: sh

   meson configure build/ -Dinstall_angle=true

`ANGLE <https://github.com/google/angle>`__ è la traduzione grafica di Google
strato, destinato a Chromium. Taisei lo impacchetta con le build di Windows
risolvere alcuni bug e problemi di prestazioni con molti driver Windows OpenGL,
e può essere facoltativamente impacchettato come renderer Metal sperimentale per
Mac OS.

Devi leggere
`questa guida <https://github.com/google/angle/blob/master/doc/DevSetup.md>`__ e
imposta il sistema di build personalizzato di Google per far funzionare le cose. Tuttavia, il sotto
i comandi potrebbero aiutarti a compilare ciò di cui hai bisogno quando hai tutto
impostare.

.. codice:: sh

   angolo cd
   python ./scripts/bootstrap.py
   sincronizzazione client
   gn gen out/x64 --args='is_debug=false dcheck_always_on=false target_cpu="x64"'
   ninja -C out/x64 libEGL libGLESv2

Produrrà due file in ``angle/out/x64``:

* ``libEGL.(*)``
* ``libGLESv2.(*)``

L'estensione del file può essere ``.dll`` per Windows, ``.dylib`` per macOS,
e ``.so`` per Linux.

Usando ``-Dinstall_angle`` e ``-Dangle_lib*`` (vedi sotto), ``meson`` copierà
quei file nel pacchetto stesso durante l'esecuzione dei passaggi di creazione del pacchetto.

Percorsi libreria ANGLE (``-Dangle_lib*``)
'''''''''''''''''''''''''''''''''''''''

* Predefinito: ``(nullo)``
* Opzioni: ``/path/to/libGLESv2.{dll,dylib,so}``/``path/to/libEGL.{dll,dylib,so}``

``-Dangle_libgles`` e ``-Dangle_libgles`` forniscono i percorsi completi per ANGLE
librerie necessarie per quel motore.

In genere, entrambi devono essere forniti contemporaneamente.

.. codice:: sh

   # per macOS
   meson configure build/ -Dangle_libgles=/path/to/libGLESv2.dylib -Dangle_libgles=/path/to/libEGL.dylib
   # per Linux
   meson configure build/ -Dangle_libgles=/path/to/libGLESv2.so -Dangle_libgles=/path/to/libEGL.so
   # per Windows
   meson configure build/ -Dangle_libgles=/path/to/libGLESv2.dll -Dangle_libegl=/path/to/libEGL.dll

Installa ANGLE (``-Dinstall_angle``)
''''''''''''''''''''''''''''''''''''

* Predefinito: ``falso``
* Opzioni: ``vero``, ``falso``

Installa le librerie ANGLE fornite sopra tramite ``-Dangle_lib*``.

Generalmente consigliato quando si confeziona ANGLE per la distribuzione.

.. codice:: sh

   meson configure build/ -Dinstall_angle=true