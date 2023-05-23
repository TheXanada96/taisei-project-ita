Il formato delle sequenze di animazione
=============================

Un'animazione è composta da una serie di sprite e da un file .ani che contiene tutti i metadati.
contiene tutti i metadati.

Il file .ani deve specificare il numero di sprite utilizzando l'opzione ``@sprite_count``
attributo. È quindi possibile definire diverse sequenze di animazione.

Le sequenze di animazione sono catene di sprite che possono essere riprodotte nel gioco. Ad esempio
esempio Cirno può volare normalmente o flettersi durante il volo. Affinché il
gioco capisca quali sprite devono essere mostrati in che ordine e con che ritardo
è necessario definire una sequenza per ogni azione.


Per definire l'azione *destra* del giocatore che vola a sinistra, ad esempio,
si scrive nel file

.. code:: c

   	right = d5 0 1 2 3

Ogni chiave del file .ani che non inizia con @ corrisponde a una sequenza.
La specifica della sequenza stessa è un elenco di indici di fotogrammi. Nell'esempio
di cui sopra, la sequenza di destra eseguirà un ciclo di fotogrammi 0-3. Tutto ciò che non è un numero
come d5 nell'esempio è un parametro:

**d<n>**
  imposta il ritardo dei fotogrammi a n. Ciò significa che ogni indice di sprite dato viene
  mostrato per n fotogrammi di gioco.
**m**
  alterna il mirroring dei fotogrammi seguenti.
**m0,m1**
  impostare il mirroring assoluto dei fotogrammi seguenti.

Tutti i parametri sono persistenti all'interno di una specifica sequenza finché non vengono modificati.

Altri esempi:

.. code:: c

	flap = d5 0 1 2 3 d2 4 5 6 7
	left = m d5 0 1 2 3
	alternateleftright = m d5 0 1 2 3 m 0 1 2 3

Ci sono molte possibilità di utilizzo ``d<n>`` Ci sono molte possibilità di utilizzo

Alcune convenzioni di denominazione
^^^^^^^^^^^^^^^^^^^^^^^

Il codice delle risorse non richiede la scelta di nomi specifici per le sequenze.
ma le diverse parti del gioco devono essere chiamate così a un certo punto.
La convenzione più comune è quella di chiamare la sequenza standard "main". Questo è
è il minimo che si debba fare per qualsiasi cosa che utilizzi un aniplayer, perché l'aniplayer deve conoscere una sequenza
aniplayer ha bisogno di conoscere un'animazione iniziale valida.

Se avete una sequenza in cui lo sprite va a sinistra o a destra, chiamatela "sinistra" e "destra".
"destra". Le animazioni del giocatore e della fata fanno questo.

Guardate i file esistenti per ulteriori esempi. Wriggle potrebbe essere interessante per
ritardi complicati e trucchi di coda.
La documentazione della struttura ``AniPlayer`` potrebbe essere interessante anche per
saperne di più sugli interni.
