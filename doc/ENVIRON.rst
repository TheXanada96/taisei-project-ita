Progetto Taisei – Variabili d'ambiente
======================================

.. Contenuti::

introduzione
------------

Alcune delle opzioni di configurazione più avanzate di Taisei sono delegate a
`ambiente
variabili <https://en.wikipedia.org/wiki/Environment_variable>`__. Questo
documento tenta di descriverli tutti.

Generalmente non è necessario impostarne nessuno. Sono destinati a
solo sviluppatori e utenti avanzati. Pertanto, la familiarità con il
si assume il concetto.

Oltre alle variabili qui elencate, quelle processate dal nostro runtime
anche le dipendenze (come SDL) hanno effetto, se non diversamente specificato.

Variabili
---------

File system virtuale
~~~~~~~~~~~~~~~~~~

**TAISEI_RES_PATH**
   | Predefinito: non impostato

   Se impostato, sovrascrive il percorso predefinito della **directory delle risorse**. Questo è
   dove Taisei cerca i dati di gioco. Il percorso predefinito è piattaforma e
   costruire specifico:

   - Su **macOS**, sarà la directory ``Contents/Resources/data``
      all'interno del bundle ``Taisei.app``.
   - Su **Linux**, **\*BSD** e la maggior parte degli altri sistemi simili a **Unix**
      (senza -DRELATIVE), sarà ``$prefix/share/taisei``. Questo
      path è statico e determinato in fase di compilazione.
   - Su **Windows** e altre piattaforme se compilato con -DRELATIVE, it
      sarà la directory ``data`` relativa all'eseguibile (o to
      qualunque ``SDL_GetBasePath`` restituisca sulla piattaforma data).

**TAISEI_STORAGE_PATH**
   | Predefinito: non impostato

   Se impostato, sovrascrive il percorso predefinito della **directory di archiviazione**. Questo è
   dove Taisei salva la configurazione, i progressi, gli screenshot e
   replay. Taisei carica anche dati personalizzati dalle ``risorse``
   sottodirectory in là, se presente, oltre alle risorse di magazzino. IL
   le risorse personalizzate oscurano quelle predefinite se i nomi sono in conflitto. IL
   il percorso predefinito è specifico della piattaforma ed è equivalente a return
   valore di ``SDL_GetPrefPath("", "taisei")``:

   - Su **Windows**, è ``%APPDATA%\taisei``.
   - Su **macOS**, è ``$HOME/Library/Application Support/taisei``.
   - Su **Linux**, **\*BSD** e la maggior parte degli altri sistemi simili a **Unix**,
      è ``$XDG_DATA_HOME/taisei`` o ``$HOME/.local/share/taisei``.

Risorse
~~~~~~~~~

**TAISEI_NOASYNC**
   | Predefinito: ``0``

   Se ``1``, disabilita il caricamento asincrono. Aumenta i tempi di caricamento, potrebbe
   ridurre leggermente l'utilizzo della CPU e della memoria durante i carichi. Generalmente no
   consigliato a meno che non incontri un bug race condition, nel qual caso
   dovresti segnalarlo.

**TAISEI_NOUNLOAD**
   | Predefinito: ``0``

   Se ``1``, le risorse caricate non vengono mai scaricate. Aumenta l'utilizzo della memoria,
   riduce le letture del filesystem e i tempi di caricamento nel tempo.

**TAISEI_NOPRELOAD**
   | Predefinito: ``0``

   Se ``1``, disabilita il precaricamento. Tutte le risorse vengono caricate solo così come sono
   sono necessari. Riduce i tempi di caricamento e l'utilizzo della memoria, ma può causare
   balbuzie durante il gioco.

**TAISEI_PRELOAD_REQUIRED**
   | Predefinito: ``0``

   Se ``1``, il gioco andrà in crash con un messaggio di errore quando tenta di farlo
   utilizzare una risorsa che non è stata precedentemente precaricata. Utile per
   sviluppatori per eseguire il debug dei precarichi mancanti.

**TAISEI_PRELOAD_SHADERS**
   | Predefinito: ``0``

   Se ``1``, Taisei caricherà tutti i programmi shader all'avvio. Questo è principalmente
   utile per gli sviluppatori per garantire rapidamente che nessuno di loro fallisca nella compilazione.

Video e OpenGL
~~~~~~~~~~~~~~~~

**TAISEI_PREFER_SDL_VIDEODRIVERS**
   | Predefinito: ``wayland,mir,cacao,windows,x11``

   Elenco dei backend video SDL che Taisei tenterà di utilizzare, nel formato
   ordine specificato, prima di tornare all'impostazione predefinita di SDL. Le voci possono essere
   separati da spazi, virgole, due punti e punti e virgola. Questa variabile è
   ignorato se ``SDL_VIDEODRIVER`` è impostato.

**TAISEI_VIDEO_DRIVER**
   | Predefinito: non impostato
   | **Deprecato**

   Utilizzare invece ``SDL_VIDEODRIVER``.

**TAISEI_RENDERER**
   | Predefinito: ``gl33``

   Seleziona il backend di rendering da utilizzare. Le opzioni attualmente disponibili sono:

      - ``gl33``: il renderer OpenGL 3.3 Core
      - ``gles30``: il renderer OpenGL ES 3.0
      - ``gles20``: il renderer OpenGL ES 2.0
      - ``null``: il renderer no-op (non viene visualizzato nulla)

   Si noti che il sottoinsieme effettivo di backend utilizzabili, nonché il valore predefinito
   scelta, può essere controllato dalle opzioni di costruzione. I backend ``gles`` non lo sono
   costruito di default.

**TAISEI_LIBGL**
   | Predefinito: non impostato

   Libreria OpenGL da caricare invece di quella predefinita. Il valore ha a
   significato specifico della piattaforma (è passato all'equivalente di ``dlopen``).
   Ha la precedenza su ``SDL_OPENGL_LIBRARY`` se impostato. Non ha effetto se
   Taisei è collegato a libgl (che non è raccomandato, perché non lo è
   portatile).

**TAISEI_GL_DEBUG**
   | Predefinito: ``0`` per build di rilascio, ``1`` per build di debug

   Abilita il debug OpenGL. Verrà richiesto un contesto di debug, tutto OpenGL
   i messaggi verranno registrati e gli errori sono fatali. Richiede ``KHR_debug``
   o l'estensione ``ARB_debug_output``.

**TAISEI_GL_EXT_OVERRIDES**
   | Predefinito: non impostato

   Elenco separato da spazi di estensioni OpenGL che si presume siano