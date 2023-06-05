
Basis Universal
===============

.. contents::

Introduzione
-----

`Basis Universal <https://github.com/taisei-project/basis_universal>`__ è un sistema di compressione delle texture su GPU con capacità
per transcodificare le immagini in un'ampia varietà di formati in tempo reale da un'unica fonte. Questo documento illustra come creare
Texture Basis Universal (``.basis``) per Taisei, ed evidenzia le limitazioni e le avvertenze del nostro supporto Basis.
First-time setup
----------------

Fase 1: L'encoder
~~~~~~~~~~~~~~~~~~~

Compilate il codificatore e mettetelo da qualche parte nel vostro ``PATH``. Supponendo di avere un clone funzionante e aggiornato del file
Il repository Taisei, compresi i sottomoduli, può essere fatto in questo modo su Linux:

.. code:: sh

    cd subprojects/basis_universal
    meson setup --buildtype=release -Db_lto=true -Dcpp_args=-march=native build
    meson compile -C build basisu
    ln -s $PWD/build/basisu ~/.local/bin

Verificare che il codificatore funzioni eseguendo ``basisu``. Dovrebbe essere stampato un lungo elenco di opzioni. Se il comando non è
trovato, assicuratevi che ``~/.local/bin`` sia nella vostra ``PATH``, oppure scegliete un'altra directory che lo sia.

Le opzioni di ottimizzazione in ``meson setup`` sono opzionali ma altamente raccomandate, in quanto il processo di codifica può essere abbastanza
lento.

È anche possibile usare `l'encoder upstream <https://github.com/BinomialLLC/basis_universal>`__, che può essere
confezionato dalla vostra distribuzione. Tuttavia, non è consigliabile. A partire dal 2020-08-06, il codificatore upstream manca di alcune
importanti ottimizzazioni delle prestazioni; 
`BinomialLLC/basis_universal#105 <https://github.com/BinomialLLC/basis_universal/pull/105>`__
`BinomialLLC/basis_universal#112 <https://github.com/BinomialLLC/basis_universal/pull/112>`__
`BinomialLLC/basis_universal#113 <https://github.com/BinomialLLC/basis_universal/pull/113>`__.

Fase 2: L'involucro
~~~~~~~~~~~~~~~~~~~

Lo script wrapper ``mkbasis'' è quello che verrà utilizzato per creare i file ``.basis''. È sufficiente un collegamento simbolico con il file
``PATH``:

.. code:: sh

    ln -s $PWD/scripts/mkbasis.py ~/.local/bin/mkbasis

Verificate che funzioni eseguendo ``mkbasis``.

Codifica TL;DR
--------------

Codificare una **mappa diffusa o ambientale** (dati sRGB, decodificati in lineari quando vengono campionati in uno shader):

.. code:: sh

    # Outputs to foo.basis
    mkbasis foo.png

    # Outputs to /path/to/bar.basis
    mkbasis foo.png -o /path/to/bar.basis

Codificare una **mappa normale dello spaziotangente** (caso speciale):

.. code:: sh

    mkbasis foo.png --normal

Codificare una **mappa di rugosità** (dati lineari a canale singolo):

.. code:: sh

    mkbasis foo.png --channels=r --linear
    # Equivalent to:
    mkbasis foo.png --r --linear

Codifica i dati di colore **RGBA** e **pre-moltiplica l'alfa**.:

.. code:: sh

    mkbasis foo.png --channels=rgba
    # Equivalent to:
    mkbasis foo.png --rgba

Codifica i dati **Gray+Alpha** e **pre-moltiplica alpha**:

.. code:: sh

    mkbasis foo.png --channels=gray-alpha
    # Equivalent to:
    mkbasis foo.png --gray-alpha

**Non** pre-moltiplicare alfa:

.. code:: sh

    mkbasis foo.png --no-multiply-alpha

Sacrificare la qualità per accelerare il processo di codifica:

.. code:: sh

    mkbasis foo.png --fast

Per un elenco completo delle opzioni e dei loro valori predefiniti, vedere
.. code:: sh

    mkbasis --help

Dettagli di codifica
----------------

Modalità di codifica
~~~~~~~~~~~~~~

Basis Universal supporta due modalità di codifica molto diverse: ETC1S e UASTC. La differenza principale tra i due è
il compromesso dimensioni/qualità.

ETC1S è la modalità predefinita. Offre una qualità medio/bassa e un'ottima compressione.

UASTC ha una qualità notevolmente superiore, ma dimensioni di file molto maggiori. Anche i file Basis con codifica UASTC devono essere aggiuntivi
compresso con uno schema basato su LZ, come deflate (zlib). I file UASTC compressi con Zopfli sono circa 4 volte più grandi
come i loro equivalenti ETC1S (comprese le mipmap), paragonabili al file sorgente memorizzato con PNG senza perdita o WebP
compressione.

Sebbene UASTC dovrebbe teoricamente funzionare, non è stato ancora ben testato con Taisei. Anche il wrapper ``mkbasis`` lo fa
non applica ancora automaticamente la compressione LZ ai file UASTC, e neanche Taisei li rileverebbe (a meno che non siano
memorizzati compressi all'interno di un pacchetto ``.zip``). Se vuoi comunque usare UASTC, passa ``--uastc`` a ``mkbasis``.
*DAFARE*


Avvertenze e limitazioni
-----------------------

*DAFARE*
