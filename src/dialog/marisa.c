/*
 * This software is licensed under the terms of the MIT License.
 * See COPYING for further information.
 * ---
 * Copyright (c) 2011-2019, Lukas Weber <laochailan@web.de>.
 * Copyright (c) 2012-2019, Andrei Alexeyev <akari@taisei-project.org>.
 */

#include "taisei.h"

#include "dialog_macros.h"

/*
 * Stage 1
 */

DIALOG_TASK(marisa, Stage1PreBoss) {
	DIALOG_BEGIN(Stage1PreBoss);

	ACTOR_LEFT(marisa);
	ACTOR_RIGHT(cirno);
	HIDE(cirno);

	FACE(marisa, puzzled);
	MSG(marisa, "Uff, di nuovo neve? Ho appena messo via il mio cappotto invernale.");
	FACE(marisa, sweat_smile);
	MSG(marisa, "…anche se siamo già a metà estate.");

	EVENT(boss_appears);
	MSG_UNSKIPPABLE(cirno, 180, "Non è bello, vero?");

	SHOW(cirno);
	FACE(cirno, normal);
	MSG(cirno, "E’ la mia neve. Ce l'ho fatta!"); 

	FACE(marisa, normal);
	MSG(marisa, "Ti dispiace se prendo in prestito dei soldi per il conto della lavanderia?");
	FACE(marisa, sweat_smile);
	MSG(marisa, "Avrei finito in autunno, ma ora…"); 

	TITLE(cirno, "Cirno", "Fata del ghiaccio termodinamica");
	MSG(cirno, "No, ma posso prestarti del gelato!");
	EVENT(music_changes);
	FACE(cirno, angry);
	MSG(cirno, "Dopo che ti faccio diventare del gelato!"); 

	FACE(marisa, smug);
	MSG(marisa, "Preferisco il ghiaccio tritato, grazie.");

	DIALOG_END();
}

DIALOG_TASK(marisa, Stage1PostBoss) {
	DIALOG_BEGIN(Stage1PostBoss);

	ACTOR_LEFT(marisa);
	ACTOR_RIGHT(cirno);
	VARIANT(cirno, defeated);
	FACE(cirno, defeated);

	FACE(marisa, smug);
	MSG(marisa, "Perché non vai a giocare con la tua nuova amica, quella dell'inferno?"); 
	MSG(marisa, "Forse con lei è uno scontro alla pari…"); 

	MSG(cirno, "Ahia…");
	MSG(cirno, "Vo-Voglio dire, l'ultima volta ha perso! E la prossima volta lo farai anche tu!");

	MSG(marisa, "Certo, Certo…");

	DIALOG_END();
}

/*
 * Stage 2
 */

DIALOG_TASK(marisa, Stage2PreBoss) {
	DIALOG_BEGIN(Stage2PreBoss);

	ACTOR_LEFT(marisa);
	ACTOR_RIGHT(hina);
	HIDE(hina);
	FACE(marisa, unamused);
	MSG(marisa, "Diamine, ora questo posto è un po' triste.");
	MSG(marisa, "Cosa potrebbe causare lo spirito a stranire l'ambiente', comunque?"); 

	EVENT(boss_appears);
	WAIT(60);
	SHOW(hina);
	FACE(hina, normal);
	MSG(hina, "Salve signorina Kirisame. Ne è passato di tempo."); 
	MSG(hina, "Sembri spericolata come al solito, Ti consiglio di tornare indietro."); 

	FACE(marisa, happy);
	MSG(marisa, "E come al solito, qua mi gioco la mia reputazione di risolutrice d'incidenti, dunque ignorerò il tuo consiglio."); 
	FACE(marisa, normal);
	MSG(marisa, "Grazie comunque. ci vediamo!"); 

	TITLE(hina, "Kagiyama Hina", "Dea giroscopica della pestilenza"); 
	FACE(hina, serious);
	MSG(hina, "Oh mio dio… sei piuttosto ribelle, vero?"); 
	MSG(hina, "Quanta confidenza, ad ignorare il mio avvertimento in quel modo");

	FACE(marisa, happy);
	MSG(marisa, "Lo prendo come un complimento.");

	EVENT(music_changes);
	MSG(hina, "E sai cosa succede alle ragazze cattive che non ascoltano i loro anziani?"); 
	MSG(hina, "Vengono inondate di sfortuna per anni!");
	DIALOG_END();
}

DIALOG_TASK(marisa, Stage2PostBoss) {
	DIALOG_BEGIN(Stage2PostBoss);

	ACTOR_LEFT(marisa);
	ACTOR_RIGHT(hina);
	VARIANT(hina, defeated);
	FACE(hina, defeated);
	FACE(marisa, unamused);
	MSG(marisa, "Sai, oggi sei molto più tagliente del solito, Hina.");
	MSG(marisa, "Sei pittosto fastidiosa, onestamente"); 

	MSG(hina, "C-che cattiveria…");
	MSG(hina, "Non hai visto che stavo solo cercando di tenerti al sicuro?");
	MSG(marisa, "Oh, ora non fare la protettiva con me."); 
	MSG(marisa, "Ne ho abbastanza per tutta la vita."); 

	DIALOG_END();
}

/*
 * Stage 3
 */

DIALOG_TASK(marisa, Stage3PreBoss) {
	DIALOG_BEGIN(Stage3PreBoss);

	ACTOR_LEFT(marisa);
	ACTOR_RIGHT(wriggle);
	HIDE(wriggle);
	FACE(marisa, normal);
	MSG(marisa, "Oggi sono tutti più spericolati. Qual'è la causa?");

	EVENT(boss_appears);
	MSG_UNSKIPPABLE(wriggle, 180, "Aspetta di vedere il loro capo!"); 
	SHOW(wriggle);

	MSG(marisa, "Sì, Sicuramente ho tanto da chiedere al loro capo.");

	MSG(wriggle, "Sentiti libera di chiedere. Sto ascoltando.");

	MSG(marisa, "Oh, sei il suo messaggero?"); 
	FACE(marisa, happy);
	MSG(marisa, "Ti dispiace passare qualcosa?"); 

	TITLE(wriggle, "Wriggle Nightbug", "L'attivista per i diritt degli insetti"); 
	FACE(wriggle, outraged);
	MSG(wriggle, "Um, OVVIAMENTE Non sono un messaggero!");
	FACE(wriggle, proud);
	MSG(wriggle, "Sono io il grande LEADER SUPREMO degli insetti!"); 

	FACE(marisa, smug);
	MSG(marisa, "Grande leader? Percaso gli insetti si sono uniti o qualcosa del genere?");

	FACE(wriggle, outraged);
	MSG(wriggle, "No! Te l'ho detto, sono il leader, la mente!");
	FACE(wriggle, calm);
	MSG(wriggle, "Quindi, quali sono le tue domande?"); 
	FACE(marisa, normal);
	MSG(marisa, "Uhm, credo di aver dimenticato."); 
	MSG(marisa, "Qual'è il tuo problema, comunque?"); 

	MSG(wriggle, "Noi insetti abbiamo tre esigenze:"); 
	MSG(wriggle, "Primo: Non usare lo spray per insetti!"); 
	MSG(wriggle, "Secondo: Scacciare gli scacciamosche!!"); 
	MSG(wriggle, "Terzo: Vogliamo il diritto di pungere e mordere!"); 
	MSG(wriggle, "Fourth—"); 

	FACE(marisa, unamused);
	MSG(marisa, "Va bene va bene, è fantastico, ma onestamente ho cose più importanti da fare."); 
	MSG(marisa, "…e non hai idea di cosa sta succedendo, vero?");

	EVENT(music_changes);
	FACE(wriggle, proud);
	MSG(wriggle, "Forse ne so più di quanto pensi."); 
	FACE(wriggle, outraged);
	MSG(wriggle, "Ma non è NIENTE che direi a un usurpatore della gloria degli insetti!"); 
	DIALOG_END();
}

DIALOG_TASK(marisa, Stage3PostBoss) {
	DIALOG_BEGIN(Stage3PostBoss);

	ACTOR_LEFT(marisa);
	ACTOR_RIGHT(wriggle);
	VARIANT(wriggle, defeated);
	FACE(wriggle, defeated);

	FACE(marisa, smug);
	MSG(marisa, "Più duro del solito, ma non abbastanza"); 
	MSG(marisa, "Dove hai appreso quelle nuove mosse, comunque?"); 

	MSG(wriggle, "Ah! Era uhm… la grande visione del nostro glorioso passato da insetto!"); 
	MSG(wriggle, "Era l'era car… car… l'Era dei Carboni!"); 

	FACE(marisa, puzzled);
	MSG(marisa, "‘Glorioso passato da insetto’? ‘Carboni’?");
	FACE(marisa, normal);
	MSG(marisa, "Ah, intendevi il periodo carbonifero. Con gli insetti giganti e tutto il resto."); 
	MSG(marisa, "Ricordo quella dottoressa nella foresta di bambù, se ne uscì con un'affermazione del genere"); 
	MSG(marisa, "Era l'unica volta che la vedevo così eccitata…"); 

	MSG(wriggle, "Sì, quello!");
	MSG(wriggle, "Vuoi allearti con noi per la nostra gloriosa conquista…?");

	FACE(marisa, smug);
	MSG(marisa, "Dopo, forse."); 
	FACE(marisa, happy);
	MSG(marisa, "Probabilmente mai.");

	DIALOG_END();
}

/*
 * Stage 4
 */

DIALOG_TASK(marisa, Stage4PreBoss) {
	DIALOG_BEGIN(Stage4PreBoss);

	ACTOR_LEFT(marisa);
	ACTOR_RIGHT(kurumi);
	HIDE(kurumi);

	FACE(marisa, surprised);
	MSG(marisa, "Oh cavolo, una villa misteriosa!"); 
	FACE(marisa, smug);
	MSG(marisa, "… quanto si può essere generici?"); 

	EVENT(boss_appears);
	MSG_UNSKIPPABLE(kurumi, 180, "E per finire, una strega occidentale!"); 
	SHOW(kurumi);
	MSG(kurumi, "L'ho già visto mille volte. È un vestito così noioso.");

	FACE(marisa, happy);
	MSG(marisa, "E quindi? Ma compenso con il mio fascino diabolico."); 

	FACE(kurumi, dissatisfied);
	MSG(kurumi, "Ma questo tema è così abusato…"); 
	FACE(kurumi, normal);
	MSG(kurumi, "Cosa c'è dopo? Una cameriera?");
	FACE(marisa, normal);
	MSG(kurumi, "Una ragazzina con quasi nessun dialogo che diventa comunque una delle preferite dei fan?"); 
	MSG(kurumi, "Che ne dite di una che avrà la sua personalità massacrata dai fan?");

	FACE(marisa, smug);
	MSG(marisa, "Oh, non ne so niente."); 

	MSG(kurumi, "Forse ho letto troppi manga che quei tengu sfornano."); 

	FACE(marisa, puzzled);
	MSG(marisa, "I tengu hanno iniziato a scrivere manga?"); 
	FACE(marisa, sweat_smile);
	MSG(marisa, "Scrivere pura narrativa è più onesto per loro, credo."); 

	TITLE(kurumi, "Kurumi", "High-Society Phlebotomist"); 
	FACE(kurumi, normal);
	MSG(kurumi, "Sì, vero?"); 
	MSG(kurumi, "Naturalmente, la maggior parte è spazzatura che piace solo agli strambi!"); 
	FACE(kurumi, dissatisfied);
	MSG(kurumi, "E non fatemi NEMMENO parlare del design di certi personaggi! Che schifo!"); 

	FACE(marisa, normal);
	MSG(marisa, "Forse dovrebbero assumere qualcuno con un po' di senso della moda."); 

	FACE(kurumi, normal);
	MSG(kurumi, "Possono chiedere pure a me!"); 
	MSG(kurumi, "Le mie idee farebbero sicuramente colpo, se riconoscessero il mio talento!"); 

	FACE(marisa, unamused);
	MSG(marisa, "Eh? forse");

	FACE(kurumi, dissatisfied);
	MSG(kurumi, "Eh?!"); 

	FACE(marisa, smug);
	MSG(marisa, "Al tuo abbigliamento manca qualcosa. Forse è caduto in disgrazia?"); 

	FACE(kurumi, tsun_blush);
	MSG(kurumi, "Tsk! Potrei dire lo stesso di te!"); 
	FACE(kurumi, normal);
	MSG(kurumi, "Sul serio, è un semplice vestito generico da strega!"); 

	FACE(marisa, normal);
	MSG(marisa, "Le mie sottovesti sono leggendarie, sai?"); 
	FACE(marisa, happy);
	MSG(marisa, "Le ragazze di tutta Gensōkyō ne parlano."); 
	FACE(marisa, normal);
	MSG(marisa, "In effetti, ce ne sono alcune, più in profondità, all'interno di questa villa."); 
	FACE(marisa, happy);
	MSG(marisa, "Allora mi sto dirigendo verso di loro.");

	EVENT(music_changes);
	FACE(kurumi, tsun);
	MSG(kurumi, "Oh, non ti lascerò andare senza combattere!"); 
	FACE(kurumi, normal);
	MSG(kurumi, "Vediamo chi è la più carina qui, strega!"); 

	DIALOG_END();
}

DIALOG_TASK(marisa, Stage4PostBoss) {
	DIALOG_BEGIN(Stage4PostBoss);

	ACTOR_LEFT(marisa);
	ACTOR_RIGHT(kurumi);
	VARIANT(kurumi, defeated);
	FACE(kurumi, defeated);

	FACE(marisa, smug);
	MSG(marisa, "Vince chi ha la sottoveste migliore. È un fatto scientifico."); 
	FACE(marisa, sweat_smile);
	MSG(marisa, "… ma da quando mi interessano i fatti scientifici?"); 

	MSG(kurumi, "U-un attimo, cosa stavo facendo?"); 
	MSG(kurumi, "(Sì, è così, fingi di avere un'amnesia…)");
	MSG(kurumi, "Uuu, non ricordo assolutamente nulla!!!"); 
	MSG(kurumi, "(Ma… non ho già visto questa ragazza dall'aspetto nerd…?)"); 

	FACE(marisa, normal);
	MSG(marisa, "Ah, scusa, scusa. Credo che tu sia scivolata e abbia battuto la testa."); 
	MSG(marisa, "Sono l'ispettrice delle… sottovesti del Gensokyo.");
	MSG(marisa, "Sono qui per controllare le sottovesti in questa villa."); 
	FACE(marisa, happy);
	MSG(marisa, "Mi avete appena fatto entrare, quindi me ne vado.");

	FACE(kurumi, normal);
	MSG(kurumi, "Uhm, Ne dubito…");
	FACE(kurumi, defeated);
	MSG(kurumi, "Non che io possa fermarti, in ogni caso…"); 
	FACE(marisa, normal);
	MSG(kurumi, "Non mi sono iscritta per essere picchiata in questo modo!"); 

	FACE(marisa, puzzled);
	MSG(marisa, "‘Iscriversi’? Pensavo che non ricordasse nulla."); 

	FACE(kurumi, tsun_blush);
	MSG(kurumi, "N-Non importa!"); 

	DIALOG_END();
}

/*
 * Stage 5
 */

DIALOG_TASK(marisa, Stage5PreBoss) {
	DIALOG_BEGIN(Stage5PreBoss);

	ACTOR_LEFT(marisa);
	ACTOR_RIGHT(iku);
	HIDE(iku);

	FACE(marisa, inquisitive);
	MSG(marisa, "Questo posto è affascinante!"); 
	MSG(marisa, "Che tipo di fonte di energia userebbero per ciò?!"); 
	MSG(marisa, "Devo dirlo a Patchy!");

	EVENT(boss_appears);
	MSG_UNSKIPPABLE(iku, 180, "Ti sconsiglio di innamorarti troppo, giovane strega.");
	SHOW(iku);
	MSG(iku, "Comunque sia, sono sorpresa di vederla qui. Come sta?");

	MSG(marisa, "In quale grimorio sarebbe questo…?" ); 
	MSG(marisa, "Uhm… probabilmente una grande illusione di qualche tipo…?");
	MSG(marisa, "Sarebbe più facile che rendere i mattoni più leggeri di una piuma, sarebbe un buon camuffamento…");

	TITLE(iku, "Nagae Iku", "Fulminologa dei cieli");
	FACE(iku, smile);
	MSG(iku, "UEhm, mi scusi. Sta parlando con se stessa?"); 

	FACE(marisa, normal);
	MSG(marisa, "Eh? No, stavo solo chiedendo.");

	MSG(iku, "Sarebbe questa la sua teoria riguardo questa torre?"); 

	MSG(marisa, "Avrebbe senso però, giusto?"); 
	FACE(marisa, inquisitive);
	MSG(marisa, "È apparso dal nulla. Se fosse stato un vero mattone, il solo spostamento dell'aria avrebbe causato un rumore enorme…");
	MSG(marisa, "E ci vorrebbe anche così tanto potere.");
	MSG(marisa, "Dunque è sicuramente una maggior illusione.");

	MSG(iku, "Sfortunatamente, credo che sia errata la premessa della sua teoria.");
	FACE(iku, eyes_closed);
	FACE(marisa, normal);
	MSG(iku, "La tecnologia che vede qua è oltre la nostra comprensione attuale."); 

	FACE(marisa, surprised);
	MSG(marisa, "Tecnologia? Wow, quindi sta dicendo che è formata da mattoni VERI?");
	FACE(marisa, normal);
	MSG(marisa, "*tap tap*"); 
	FACE(marisa, surprised);
	MSG(marisa, "Fa così freddo che è quasi inquietante, come se mi stesse succhiando la magia dalle dita."); 
	FACE(marisa, inquisitive);
	MSG(marisa, "Ma questo significa che la torre… ha una forma corporea?!");
	MSG(marisa, "Diamine! Ora DEVO incontrare il proprietario!");
	MSG(marisa, "Che grimori possiede per tirare fuori qualcosa del genere?!"); 

	FACE(iku, smile);
	MSG(iku, "N-non sta usando grimori, o magia in generale.");
	FACE(iku, serious);
	MSG(iku, "Si affida a macchinari complessi e probabilmente computazionali avanzati");

	MSG(marisa, "Ma quindi, quale sarebbero le fonti energetiche?");
	MSG(marisa, "Nemmeno la fusione nucleare potrebbe sostenere una cosa del genere!");

	FACE(iku, smile);
	MSG(iku, "I-io non sono sicura della sua meccanica esatta—");

	FACE(marisa, happy);
	MSG(marisa, "Dove pensi che sia?");

	FACE(iku, normal);
	MSG(iku, "Intendi…?");

	FACE(marisa, inquisitive);
	MSG(marisa, "Esatto, La proprietaria! E' di sopra, vero?");

	FACE(iku, serious);
	MSG(iku, "Forse l'atmosfera rarefatta a questa quota ti ha dato alla testa. Non dovrei divulgare ulteriori informazioni, per la tua protezione.");

	FACE(marisa, happy);
	MSG(marisa, "Come si chiama?"); 

	MSG(iku, "Mi stai ascoltando? Non stai ragionando in modo chiaro!");

	FACE(marisa, inquisitive);
	MSG(marisa, "Hai qualche consiglio su come parlare con lei, magari per farla rilassare un po'?");
	FACE(marisa, happy);
	MSG(marisa, "Non voglio sprecare la mia occasione.");

	FACE(iku, smile);
	MSG(iku, "Sto cercando di risparmiarle ulteriori pericoli, ma tutto quello che può fare è parlare di me. Sii più premurosa.");
	MSG(iku, "Mi aspettavo che fosse stata in grado di affrontare la cosa con una mente lucida e risolvere questo incidente, ma sembra—");

	FACE(marisa, normal);
	MSG(marisa, "Ah, ah, capisco. Dovrò attivare il vecchio fascino Kirisame.");
	FACE(marisa, smug);
	FACE(iku, serious);
	MSG(marisa, "Ho capito, Ho capito."); 
	MSG(marisa, "Non facevo la ‘femme fatale’ da un po’, però…"); 

	EVENT(music_changes);

	MSG(iku, "Basta!"); 
	MSG(iku, "Si dice che l'elettrostimolazione applicata in modo specifico possa rilassare la mente.");
	MSG(iku, "Mi permetta per metterlo in pratica per lei!"); 

	DIALOG_END();
}

DIALOG_TASK(marisa, Stage5PostMidBoss) {
	DIALOG_BEGIN(Stage5PostMidBoss);

	ACTOR_LEFT(marisa);
	FACE(marisa, surprised);

	// should be only one message with a fixed 180-frame (3 second) timeout
	MSG_UNSKIPPABLE(marisa, 180, "Quindi questo posto funziona con l'elettricità, eh? Uhm…");

	DIALOG_END();
}

DIALOG_TASK(marisa, Stage5PostBoss) {
	DIALOG_BEGIN(Stage5PostBoss);

	ACTOR_LEFT(marisa);
	ACTOR_RIGHT(iku);
	VARIANT(iku, defeated);
	FACE(iku, defeated);

	FACE(marisa, normal);
	MSG(marisa, "Oof, spero che non mi abbia reso i capelli troppo crespi.");
	FACE(marisa, happy);
	MSG(marisa, "Sai, per la mia prima impressione e tutto.");

	FACE(iku, eyes_closed);
	MSG(iku, "T-te lo dirò per l'ultima volta, non avrà niente da insegnarti…"); 
	MSG(iku, "I suoi poteri si basano sulla tecnologia e sul metodo scientifico. Di questo sono sicura.");

	FACE(marisa, unamused);
	MSG(marisa, "L'unica volta che Sanae non è in giro per smanettare su tutte le cose scientifiche, eh?"); 
	FACE(iku, normal);
	FACE(marisa, normal);
	MSG(marisa, "Ah bene, so come far funzionare uno di quei telefoni intelligenti, la tecnologia di questa torre è molto avanzata, quindi dovrebbe funzionare bene."); 
	FACE(marisa, inquisitive);
	MSG(marisa, "A proposito, hai sentito quella strana voce?"); 

	MSG(iku, "Strana voce?"); 

	FACE(marisa, smug);
	MSG(marisa, "Sì, continua a dirmi che non sto pensando in modo chiaro, etc…"); 
	MSG(marisa, "Probabilmente solo quegli strani raggi della follia che cercano di prendermi."); 

	FACE(iku, eyes_closed);
	MSG(iku, "Uff, quanto sei sciocca."); 
	MSG(iku, "Ma forse stai pensando abbastanza bene per risolvere questo incidente, dopotutto…"); 

	FACE(marisa, surprised);
	MSG(marisa, "Ah! Ecco di nuovo quella voce! Così strano…");

	DIALOG_END();
}

/*
 * Stage 6
 */

DIALOG_TASK(marisa, Stage6PreBoss) {
	DIALOG_BEGIN(Stage6PreBoss);

	ACTOR_LEFT(marisa);
	ACTOR_RIGHT(elly);
	HIDE(elly);

	EVENT(boss_appears);
	MSG_UNSKIPPABLE(elly, 180, "Stavo aspettando la tua mossa.");
	SHOW(elly);
	MSG(elly, "Furtiva come sei, ma continui a fare rumore."); 

	FACE(marisa, unamused);
	MSG(marisa, "Uhm…"); 
	FACE(elly, smug);
	MSG(elly, "Pensavi davvero che non avrei notato tutto il trambusto che hai causato all'interno della torre?");

	MSG(marisa, "Uhmmmmmmmmmmmmmmmmmmmmmmmmm…");

	FACE(elly, angry);
	MSG(elly, "Smettila di fare l'insolente e parla!");

	FACE(marisa, unamused);
	MSG(marisa, "…asd… non fare l'obamica"); 

	FACE(elly, normal);
	MSG(elly, "…c-che cos'è"); 

	FACE(marisa, unamused);
	MSG(marisa, "Dopotutto non sembri una maga.");
	MSG(marisa, "Sono alquanto delusa."); 
	MSG(marisa, "Onestamente, questo potrebbe essere l'incidente più deludente di sempre.");

	TITLE(elly, "Elly", "La mietitrice teorica"); 
	MSG(elly, "Stai cercando… la magia?"); 
	FACE(elly, smug);
	MSG(elly, "Ah! Ti pentirai di aver sprecato il tuo tempo in queste sciocchezze."); 
	MSG(elly, "Presto capirai l'errore di-"); 

	MSG(marisa, "Sai quanto è noioso essere un mago in Gensōkyō di questi tempi?"); 

	FACE(elly, eyes_closed);
	MSG(elly, "Non me ne frega un-");

	MSG(marisa, "Sul serio! Di recente è stato solo ‘Dio questo’ e ‘Altro Mondo quello’."); 
	MSG(marisa, "Reimu ha appreso alcune abilità dolci, ma io? Nulla!"); 
	MSG(marisa, "Anche gli dei usano la magia, però sono come lei! Non hanno bisogno di libri"); 
	MSG(marisa, "Invece io sì! E finisco sempre a mani vuote ogni volta!");

	FACE(elly, angry);
	MSG(elly, "HO DETTO CHE NON ME NE FREGA NULLA sulla tua stupida mag-");

	MSG(marisa, "Ho visto questo posto e mi sono detta ‘Wow! Ma sono tutti incantesimi o simili?"); 
	FACE(marisa, inquisitive);
	MSG(marisa, "Mi ero veramente emozionata!"); 
	MSG(marisa, "Forse potrei ottenere una nuova carta vincente da ciò’ ho pensato.");
	FACE(marisa, unamused);
	MSG(marisa, "Ma ovviamente sei uno shinigami o qualcosa di simile. E non ho visto una biblioteca…");
	MSG(marisa, "Immagino che quel pesce remo di prima avesse ragione.");
	MSG(marisa, "Master Spark è buono in tutto, ma mi porterà solo così lontano nella vita…"); 

	FACE(elly, eyes_closed);
	MSG(elly, "…"); 
	MSG(elly, "Hai finito finalmente?"); 
	FACE(elly, angry);
	MSG(elly, "E' percaso uno scherzo?!");
	FACE(elly, shouting);
	MSG(elly, "Mi di prendendo in giro come hai fatto la prima volta che ci siamo incontrati?!");

	MSG(marisa, "Almeno quella volta facevi la guardia a qualcosa di potente che avrei potuto usare."); 
	MSG(marisa, "Sto cercando di ricordare, anche quella volta è stato un fallimento?"); 
	FACE(marisa, happy);
	MSG(marisa, "Almeno ho incontrato Yuuka, giusto? Sapevi che ha finito per darmi il mio marchio di fabbrica?");
	MSG(marisa, "Non in quel momento, e non volontariamente, tuttavia-"); 

	FACE(elly, angry);
	MSG(elly, "Te lo ricordi?! Ma come-?!"); 
	MSG(elly, "...uff, non importa! Non è che tu possa afferrare il vero potere della Torre."); 
	FACE(elly, smug);
	MSG(elly, "Dopotutto, posso già percepire la tua debole mente soccombere alla sua potenza!");

	FACE(marisa, unamused);
	MSG(marisa, "Eh? Non sono depressa o triste. Sono solo delusa."); 

	FACE(elly, shouting);
	MSG(elly, "N-Non si tratta di essere 'depressi'! Si tratta di essere sopraffatti dalla vasta conoscenza dell'universo!");
	MSG(elly, "Una volta realizzato il vero potenziale della realtà, impazzirai per la conoscenza!");
	MSG(elly, "Non vedi?! Niente può fermarci adesso! Perché noi siamo—!");

	FACE(marisa, surprised);
	MSG(marisa, "Ma sono già pazza con la conoscienza! Pensi che sia un'alcolista anonima?!");
	MSG(marisa, "La mia mente corre sempre con questo e quello..."); 
	MSG(marisa, "Pensi che questo sia diverso da come vivo di solito?! Supera te stessa!");
	FACE(marisa, inquisitive);
	MSG(marisa, "Ora, devo chiedertelo... veramente non hai una biblioteca segreta da nessuna parte?"); 
	MSG(marisa, "Una sola libreria?! Qualche nota scarabocchiata?!"); 
	MSG(marisa, "Diamine, prenderò anche uno di quei piccoli tablet luminosi con tutti quei ‘Piddieffe’ dentro! Fanno male agli occhi, ma—"); 

	FACE(elly, eyes_closed);
	MSG(elly, "Finché OVVIAMENTE tratti ciò come uno scherzo, MI RIFIUTO di parlare ancora con te"); 

	FACE(marisa, happy);
	MSG(marisa, "Oh andiamo, vuoi recuperare i vecchi tempi?"); 
	MSG(marisa, "Qualunque cosa sia spegnila ed usciremo per bere qualcosa! C'è questo bel nuovo bar in città con un simpatico—"); 

	MSG(elly, "Non c'è forza in questo mondo che mi farebbe tornare indietro adesso!");
	EVENT(music_changes);
	FACE(elly, smug);
	MSG(elly, "Qualcuno così ‘ordinario’ come te che ti metti sulla nostra strada è impressionante, ti darò così tanto.");
	FACE(elly, angry);
	MSG(elly, "Ma non c'è posto per la stregoneria nella nostra visione illuminata di Gensōkyō!");
	FACE(elly, shouting);
	MSG(elly, "Ora, soccombi nella follia!"); 

	DIALOG_END();
}

DIALOG_TASK(marisa, Stage6PreFinal) {
	DIALOG_BEGIN(Stage6PreFinal);

	ACTOR_LEFT(marisa);
	ACTOR_RIGHT(elly);
	VARIANT(elly, beaten);
	FACE(elly, angry);
	FACE(marisa, unamused);
	MSG(marisa, "Sei sicura di non avere un libro degli incantesimi in giro?! Niente di niente?!"); 
	MSG(elly, "Ne parli ancora?! Va bene, guarda quello che ti pare!"); 
	FACE(elly, shouting);
	MSG(elly, "La tua pietosa magia non vale nulla contro la vera natura della realtà!"); 

	DIALOG_END();
}

/*
 * Register the tasks
 */

#define EXPORT_DIALOG_TASKS_CHARACTER marisa
#include "export_dialog_tasks.inc.h"
