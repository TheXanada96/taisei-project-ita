Taisei Project - Controller Settings
====================================

Come usare i controller, come i gamepad, con Taisei.

.. contents::

Controller Support
------------------

Supported Controllers
"""""""""""""""""""""

Taisei uses SDL2's unified
`GameController API <https://wiki.libsdl.org/CategoryGameController>`__.
Questo ci consente di supportare correttamente qualsiasi dispositivo che SDL riconosce per impostazione predefinita,
pur trattandoli tutti allo stesso modo. La stragrande maggioranza di dispositivi USB
dovrebbero essere supportati da questo metodo, specialmente quelli realizzati in
negli ultimi 15 anni circa, una volta che l'intero ecosistema USB ha iniziato a stabilizzarsi.

Unsupported Controllers
"""""""""""""""""""""""

Se, per qualche motivo, il tuo dispositivo non è supportato dall'API GameController di SDL2, ad esempio
un controller di gioco particolarmente vecchio o forse personalizzato utilizzando un'interfaccia unica, lo farai
è necessario fornirgli una mappatura del controller personalizzata.

There are a few ways to generate a custom mapping:

-  You can use the
   `controllermap <https://aur.archlinux.org/packages/controllermap>`__ utility,
   che `viene fornito con il codice sorgente SDL
   <https://hg.libsdl.org/SDL/file/68a767ae3a88/test/controllermap.c>`__.
- Se usi Steam, puoi configurare il tuo controller lì. Quindi puoi aggiungere
   Taisei come gioco non Steam; eseguirlo da Steam e tutto dovrebbe *funzionare™*. 
   Nel caso non volessi farlo, trova ``config/config.vdf`` nel tuo file
   Directory di installazione di Steam e cerca la variabile ``SDL_GamepadBind``.
   Contiene un elenco di mappature SDL separate da interruzioni di riga.
-  Puoi anche provare `SDL2 Gamepad Tool di General Arcade
   <http://www.generalarcade.com/gamepadtool/>`__. Questo programma è gratuito,
   ma non open source.
- Infine, puoi provare a scrivere una mappatura a mano. Probabilmente dovrai
   fare riferimento alla documentazione SDL. Vedere `gamecontrollerdb.txt
   <misc/gamecontrollerdb/gamecontrollerdb.txt>`__ per altri esempi.

Sia che tu usi uno degli strumenti di cui sopra, sia che tu ne faccia uno tu stesso, il file mapping
dovrebbe assomigliare a questo:

::

    03000000ba2200002010000001010000,Jess Technology USB Game Controller,a:b2,b:b1,back:b8,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,guide:,leftshoulder:b4,lefttrigger:b6,leftx:a0,lefty:a1,rightshoulder:b5,righttrigger:b7,rightx:a3,righty:a2,start:b9,x:b3,y:b0,

Una volta che hai la tua mappatura, ci sono due modi per farla usare a Taisei:

-  Crea un file chiamato ``gamecontrollerdb.txt`` dove la tua configurazione, replay e
   gli screenshot sono e mettono ogni mappatura su una nuova riga.
-  Metti le tue mappature nella variabile d'ambiente ``SDL_GAMECONTROLLERCONFIG``,
   anche separati da interruzioni di riga. Altri giochi che utilizzano l'API GameController
   li raccoglierà anche.

Quando hai finito, considera di contribuire con le tue mappature a
`SDL <https://libsdl.org/>`__,
`SDL_GameControllerDB <https://github.com/gabomdq/SDL_GameControllerDB>`__,
and `us <https://github.com/taisei-project/SDL_GameControllerDB>`__, so
che altre persone possano beneficiare del tuo lavoro.

Si noti inoltre che attualmente gestiamo solo input da assi analogici e
pulsanti analogici/digitali. Qualcosa di più esotico, come i cappelli, probabilmente non funzionerà
fuori dalla scatola.