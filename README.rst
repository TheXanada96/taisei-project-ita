Taisei Project
==============

.. image:: misc/icons/taisei.ico
   :width: 150
   :alt: Taisei Project icon

.. contents::

Introduzione
------------

Traduzione italiana
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Prima di tutto grazie mille a tutti coloro che sono stati coinvolti nello sviluppo del gioco, specialmente Akari che mi ha guidato 
ai file da modificare e XalkasITA2K per avermi aiutato nella traduzione.
È stato fatto un bel lavoro di controllo, linea per linea, giorno dopo giorno, senza interruzioni;
Ci fa piacere trovare queste perle fanmade, e vogliamo aiutare la comunità italiana a far conoscere il gioco.


A proposito di Taisei Project
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Taisei Project è un fan-game open source ambientato nel mondo di
`Tōhō Project <https://en.wikipedia.org/wiki/Touhou_Project>`__.
È un gioco shot'em up a scorrimento verticale dall'alto verso il basso (STG).
noto come "bullet hell" o "danmaku". Gli STG sono giochi frenetici incentrati su
riconoscimento di modelli e padronanza attraverso la pratica.

Taisei Project è altamente portabile ed è scritto in C11, utilizzando SDL2 con un'estensione
renderizzatore OpenGL. È ufficialmente supportato su Windows, Linux, macOS e
tramite browser abilitati per WebGL come Firefox e browser basati su Chromium
(Chrome, Edge, ecc.). Può anche essere compilato per una serie di altri sistemi operativi.

Per gli screenshot del gameplay, vedere
`il nostro loro sito web <https://taisei-project.org/media>`__.

Per le istruzioni di gioco, leggere `questo <doc/GAME.rst>`__.

per la storia, leggere `questo <doc/STORY.txt>`__. (Attenzione SPOILER!)

A proposito di Taisei Project
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Tōhō Project è una serie di giochi indipendenti (nota anche come "doujin" in giapponese)
noto per il suo cast corale di personaggi e colonne sonore memorabili.
È prodotto in generale da un singolo artista noto come ZUN e ha una
`licenza permessiva <https://en.touhouwiki.net/wiki/Touhou_Wiki:Copyrights#Copyright_status.2FTerms_of_Use_of_the_Touhou_Project>`__
che consente l'esistenza legale di opere derivate indipendenti come Taisei Project.

Taisei *non* è un "clone" di Tōhō, e racconta una storia originale a sé stante con
musica, arte, meccaniche di gioco e codebase. Mentre una certa familiarità con Tōhō
è utile, il gameplay può essere apprezzato senza una conoscenza preliminare
della serie.

Per avere più informazioni sui doujin,
`clicca qui <https://en.wikipedia.org/wiki/D%C5%8Djin>`__.

Installazione
------------

Puoi trovare i binari precompilati del gioco completo sulla pagina
`Releases <https://github.com/taisei-project/taisei/releases>`__ di
GitHub, disponibile per Windows (x86/x64), Linux, and macOS.

Esiste anche una build sperimentale per Nintendo Switch (homebrew) (usala a
tuo rischio).

Puoi anche riprodurre la nostra build WebGL sperimentale tramite il tuo browser web
`qui <https://play.taisei-project.org/>`__. (funziona su browser basati su chromium e basati su Firefox)

Codice Sorgente e sviluppo
-------------------------

Ottenimento del Codice Sorgente
^^^^^^^^^^^^^^^^^^^^^

Sorgente
______

Si consiglia di recuperare il codice sorgente utilizzando ``git``:

.. code:: sh

    git clone --recurse-submodules https://github.com/taisei-project/taisei

Dovresti anche eseguire ``git submodule update`` ogni volta che entri un
nuovo codice, controlla un altro ramo o esegui qualsiasi azione ``git``.
 Il ``./pull``e gli script helper ``./checkout`` possono farlo automaticamente.

Archiviazione
_______

⚠️ **NOTA**: A causa del modo in cui GitHub impacchetta il codice sorgente, ``Download ZIP``
link sul repository principale *non funziona*.

Ciò è dovuto al fatto che GitHub non impacchetta i sottomoduli insieme al
codice sorgente quando genera automaticamente i file ``.zip``. Abbiamo invece creato gli
archivi manualmente e **DEVI** scaricare l'archivio dalla pagina.
`Releases <https://github.com/taisei-project/taisei/releases>`__ .

Compilando il Codice Sorgente
^^^^^^^^^^^^^^^^^^^^^

Al momento, consigliamo di creare Taisei su un sistema simile a POSIX (Linux, macOS,
eccetera).

Sebbene Taisei sia altamente configurabile, il modo più semplice per compilare il codice per
la tua macchina host è:

.. code:: sh

    meson setup build/
    meson compile -C build/
    meson install -C build/

Segui il `Building <./doc/BUILD.rst>`__ doc per avere più informazioni su come compilarlo.
Taisei, and its list of dependencies.

Replays, Screenshots, and Impostazioni di locazione
--------------------------------------------

Taisei stores all data in a platform-specific directory:

-  Su **Windows**, probabilmente su ``%APPDATA%\taisei``
-  Su **macOS**, è ``$HOME/Library/Application Support/taisei``
-  Su **Linux**, **\*BSD**, e altri sistemi **Unix**-like, è
   ``$XDG_DATA_HOME/taisei`` o ``$HOME/.local/share/taisei``

Questa è denominata **Directory di archiviazione**. È possibile impostare l'ambiente
variabile ``TAISEI_STORAGE_PATH`` per sovrascrivere questo comportamento.

Risoluzione dei problemi
---------------

La documentazione per molti argomenti, inclusi sviluppo e controlli di gioco
, può essere trovata nella nostra sezione `docs <./doc/README.rst>`__.


Contatti
-------

-  https://taisei-project.org/

-  `Il loro server Discord <https://discord.gg/JEHCMzW>`__
