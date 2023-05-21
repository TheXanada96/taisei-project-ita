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

DIALOG_TASK(reimu, Stage1PreBoss) {
	PRELOAD {
		PRELOAD_CHAR(reimu) {
			PRELOAD_FACE(normal);
			PRELOAD_FACE(unamused);
			PRELOAD_FACE(sigh);
		}

		PRELOAD_CHAR(cirno) {
			PRELOAD_FACE(normal);
			PRELOAD_FACE(angry);
		}
	}

	// Initialization, must be at the very top (after PRELOAD).
	DIALOG_BEGIN(Stage1PreBoss);

	ACTOR_LEFT(reimu);
	ACTOR_RIGHT(cirno);

	// Hide cirno for now, to be revealed later.
	HIDE(cirno);

	// Let’s wait a bit, then change Reimu’s expression.
	// All timings are in frames (60 = 1 sec).
	WAIT_SKIPPABLE(60);
	// "normal" is the default face.
	FACE(reimu, normal);

	// MSG() makes the actor say a line, and then waits an unspecified amount of time (skippable).
	// The timeout is determined by the dialog_util_estimate_wait_timeout_from_text() function in dialog.c
	MSG(reimu, "Neve fuori stagione? Mi chiedo se sia di nuovo quella ‘divinità segreta’…");

	// EVENT()s are handled by stage code.
	// You can find the list of events per dialogue in dialog_interface.h
	// All of them should be signaled eventually.
	EVENT(boss_appears);

	// MSG_UNSKIPPABLE() is like MSG(), but can’t be skipped and takes an explicit timeout.
	// Wait until the boss slides in.
	MSG_UNSKIPPABLE(cirno, 180, "Mi hai appena definita ‘Divinità’?"); 

	// Reveal Cirno’s portrait
	SHOW(cirno);
	MSG(cirno, "Cosa, sei *così* colpita dalla mia incredibile magia?!"); 

	FACE(reimu, sigh);
	MSG(reimu, "Certo, mi ero completamente dimenticata di te prima."); 
	MSG(reimu, "Avrei dovuto saperlo.");

	// Titles are not yet implemented, but this should work once they are.
	// Right now this does nothing.
	TITLE(cirno, "Cirno", "Fata del ghiaccio termodinamica");
	MSG(cirno, "Era meglio saperlo piuttosto che intromettersi nella mia tana segreta!"); 

	FACE(reimu, normal);
	MSG(reimu, "Beh, se *sei* eccitata, immagino che stia succedendo davvero qualcosa."); 
	MSG(reimu, "Tuttavia chiedo il permesso di passare…"); 

	EVENT(music_changes);
	FACE(cirno, angry);
	MSG(cirno, "Non è possibile! Preparati a essere raffreddata fino all'ultimo osso!");

	// Teardown, must be at the very bottom.
	DIALOG_END();
}

DIALOG_TASK(reimu, Stage1PostBoss) {
	DIALOG_BEGIN(Stage1PostBoss);

	ACTOR_LEFT(reimu);
	ACTOR_RIGHT(cirno);

	// VARIANT() changes the base body sprite.
	// Bosses currently only have a "defeated" variant with some clothing damage, to be used in post-battle scenes.
	// Elly’s is called "beaten" and is slightly subdued.
	VARIANT(cirno, defeated);

	// Bosses also have a "defeated" face to go along with the variant, but all the other faces can be used as well.
	// It’s best to set the face to "defeated" in the beginning of a post-battle dialogue, and change it later if needed.
	FACE(cirno, defeated);
	MSG(cirno, "Calmati! Non intendevo in questo modo."); 
	FACE(reimu, smug);
	MSG(reimu, "Ho chiesto il permesso di passare, sai."); 
	MSG(cirno, "Non me lo ricordo! Hai infranto le regole! non ero ancora pronta…");

	DIALOG_END();
}

/*
 * Stage 2
 */

DIALOG_TASK(reimu, Stage2PreBoss) {
	DIALOG_BEGIN(Stage2PreBoss);

	ACTOR_LEFT(reimu);
	ACTOR_RIGHT(hina);

	HIDE(hina);
	WAIT_SKIPPABLE(60);

	FACE(reimu, normal);
	MSG(reimu, "In assenza di quei kappa chiacchieroni, la montagna risulta praticamente abbandonata."); 
	FACE(reimu, sigh);
	MSG(reimu, "E' come se ne sentissi la mancanza."); 

	EVENT(boss_appears);
	MSG_UNSKIPPABLE(hina, 180, "Ah, è la Signora Hakurei.");
	SHOW(hina);
	FACE(reimu, normal);
	FACE(hina, normal);
	MSG(hina, "Ho pensato che avresti potuto raggiungermi."); 
	FACE(hina, concerned);
	MSG(hina, "Ma ancora una volta, stai cercando di andare in posti dove non dovresti.");
	MSG(hina, "Che ragazza problematica…"); 

	FACE(reimu, sigh);
	MSG(reimu, "Essendo questa montagna ‘abbandonata’…");
	FACE(reimu, normal);
	MSG(reimu, "Sai almeno da cosa mi stai proteggendo questa volta?"); 

	TITLE(hina, "Kagiyama Hina", "Dea giroscopica della pestilenza"); 

	FACE(hina, normal);
	MSG(hina, "Una ragazza brillante come te dovrebbe sapere che il monte Yōkai è particolarmente pericoloso oggi.");
	FACE(hina, concerned);
	MSG(hina, "Dovresti tornare indietro adesso, mia cara."); 

	FACE(reimu, sigh);
	MSG(reimu, "Lei… ha completamente ignorato la mia domanda."); 
	FACE(reimu, puzzled);
	MSG(reimu, "Ha importanza che gli Dei mi abbiano chiesto di venire questa volta?"); 

	EVENT(music_changes);

	MSG(hina, "In questo caso, sono sicura di saperne di più degli dei della montagna."); 
	MSG(hina, "Se non torni subito indietro, dovrò respingerti con la forza."); 

	FACE(reimu, sigh);
	MSG(reimu, "Così fastidiosa…"); 

	DIALOG_END();
}

DIALOG_TASK(reimu, Stage2PostBoss) {
	DIALOG_BEGIN(Stage2PostBoss);

	ACTOR_LEFT(reimu);
	ACTOR_RIGHT(hina);

	WAIT(30);

	VARIANT(hina, defeated);
	FACE(hina, defeated);
	FACE(reimu, normal);

	MSG(hina, "Quindi ho perso.… dunque puoi proseguire, suppongo."); 
	FACE(reimu, puzzled);
	MSG(reimu, "Ormai dovresti sapere che posso farcela. Perché sei così prepotente?"); 
	MSG(hina, "L'importante è non affermare che non ti avevo avvisata, qualora inevitabilmente verrai sbranata da qualunque cosa ci sia là fuori…"); 

	FACE(reimu, unamused);
	MSG(reimu, "(Ignorata nuovamente...)");

	DIALOG_END();
}

/*
 * Stage 3
 */

DIALOG_TASK(reimu, Stage3PreBoss) {
	DIALOG_BEGIN(Stage3PreBoss);

	ACTOR_LEFT(reimu);
	ACTOR_RIGHT(wriggle);
	HIDE(wriggle);
	FACE(reimu, normal);
	MSG(reimu, "Nonostante tutti siano impazziti, non riesco ancora a vedere nulla di anormale."); 

	EVENT(boss_appears);
	MSG_UNSKIPPABLE(wriggle, 180, "Bene, ai tuoi occhi umani, gli insetti possono sembrare ‘normali’…"); 

	SHOW(wriggle);
	FACE(wriggle, proud);
	MSG(wriggle, "… ma c'è stato un periodo in cui avevamo la supremazia!"); 

	FACE(reimu, puzzled);
	MSG(reimu, "Eh? Tu? Non sei un po' lontano da casa?"); 
	MSG(reimu, "Inoltre, ‘supremazia'? Non ho mai sentito parlare di insetti che governano Gensōkyō.");

	TITLE(wriggle, "Wriggle Nightbug", "Attivista dei Diritti degli Insetti"); 
	FACE(wriggle, outraged);
	MSG(wriggle, "Casa?  tu ti sei intromessa nella mia tana segreta!"); 

	FACE(reimu, sigh);
	MSG(reimu, "Ancora con questa ‘tana segreta’…");
	FACE(wriggle, proud);
	MSG(wriggle, "Hai mai sentito parlare del Car—…"); 
	MSG(wriggle, "Carb—…"); // "Carb—…"
	FACE(reimu, puzzled);
	MSG(wriggle, "Vabbè quel periodo della storia?"); 
	MSG(wriggle, "È stato il momento più bello, tutti dovrebbero averne sentito parlare ormai!"); 

	MSG(reimu, "Mi sembra abbastanza inverosimile, onestamente. Ma voi yōkai tirate fuori sempre le teorie più assurde…"); 

	FACE(wriggle, outraged);
	MSG(wriggle, "Non paragonare noi grandi insetti a dei comuni yōkai!"); 
	FACE(wriggle, proud);
	MSG(wriggle, "Porterò la mia stirpe agli antichi fasti!"); 

	FACE(reimu, puzzled);
	MSG(reimu, "Insetti giganti? Ma sei minuscolo."); 
	FACE(reimu, unamused);
	MSG(reimu, "E ancora non so cosa intendi per ‘antichi fasti.’");

	EVENT(music_changes);

	MSG(wriggle, "Non sembri molto informata sulla nostra storia."); 
	MSG(wriggle, "Quindi lascia che diventi il tuo insegnante!"); 
	DIALOG_END();
}

DIALOG_TASK(reimu, Stage3PostBoss) {
	DIALOG_BEGIN(Stage3PostBoss);

	ACTOR_LEFT(reimu);
	ACTOR_RIGHT(wriggle);

	VARIANT(wriggle, defeated);
	FACE(wriggle, defeated);

	FACE(reimu, smug);
	MSG(reimu, "Insetti giganti che vagano per Gensōkyō, eh?"); 
	MSG(reimu, "Suona come uno degli esperimenti ‘nucleari’ di Sanae.");

	MSG(wriggle, "M-ma l'ho visto chiaramente… il destino degli insetti…");

	FACE(reimu, normal);
	MSG(reimu, "Non hai un buon affare così com'è, però"); 
	MSG(reimu, "Praticamente possiedi le foreste del Gensōkyō.");

	MSG(wriggle, "Ma non possiamo mai sperare di più…?"); 

	DIALOG_END();
}

/*
 * Stage 4
 */

DIALOG_TASK(reimu, Stage4PreBoss) {
	DIALOG_BEGIN(Stage4PreBoss);

	ACTOR_LEFT(reimu);
	ACTOR_RIGHT(kurumi);

	HIDE(kurumi);

	FACE(reimu, puzzled);
	MSG(reimu, "Eh? C'è una villa che sporge da questa torre?"); 
	FACE(reimu, sigh);
	MSG(reimu, "Ciò è più insensato del solito."); 

	EVENT(boss_appears);
	WAIT(30);

	FACE(reimu, normal);
	MSG(reimu, "E tu, chi dovresti essere?"); 

	SHOW(kurumi);
	FACE(kurumi, tsun);
	MSG(kurumi, "Oh, questo dovrei chiederlo io"); 

	FACE(reimu, puzzled);
	MSG(reimu, "…?");
	FACE(reimu, unamused);
	MSG(reimu, "E cosa stai facendo, comunque?");
	MSG(reimu, "Sei dietro a tutti questi… strani pensieri che tutti hanno?"); 

	FACE(kurumi, normal);
	TITLE(kurumi, "Kurumi", "Flebotomista dell'alta società"); 
	MSG(kurumi, "Non ho idea di cosa intendi per ‘strani pensieri’, ma sarò onesto con te…"); 
	MSG(kurumi, "I tuoi vestiti mi stanno dando degli strani pensieri!"); 
	MSG(kurumi, "Dove hai preso quel vestito?! Dal cassonetto?! Davvero!"); 

	FACE(reimu, unamused);
	MSG(reimu, "Ugh, un'altra signorina che abita in una villa…"); 
	FACE(reimu, sigh);
	MSG(reimu, "Pensavo di ricordarti da qualche parte, ma no. Assolutamente no."); 
	FACE(reimu, assertive);
	MSG(reimu, "Solo… ferma qualunque cosa tu stia facendo, adesso.");

	FACE(kurumi, dissatisfied);
	MSG(kurumi, "Una volta che avrai un po' di senso della moda, forse lo farò!"); 

	FACE(reimu, unamused);
	MSG(reimu, "… quindi *ci sei* dietro, eh?"); 
	FACE(reimu, sigh);
	MSG(reimu, "E poi, non hai mai visto una sacerdotessa prima d'ora?"); 

	FACE(kurumi, normal);
	MSG(kurumi, "Tu saresti una sacerdotessa?"); 
	FACE(reimu, unamused);
	MSG(kurumi, "Forse volevi dire NETTURBINA"); 

	FACE(reimu, assertive);
	MSG(reimu, "Q-questo è quello che indossa una sacerdotessa. È un'uniforme."); 

	MSG(kurumi, "Uniforme? Mi stai prendendo in giro?"); 
	MSG(kurumi, "Ho avuto modo di conoscere una vera sacerdotessa, e lei non ti somigliava per niente!"); 
	MSG(kurumi, "Cosa sono questi schemi, comunque? È completamente poco ortodosso!"); 
	MSG(kurumi, "Non sta nemmeno usando il giusto tipo di tessuto! Esci di qui, finta sacerdotessa!"); 

	FACE(reimu, irritated);
	MSG(reimu, "… ARGH!"); 
	FACE(reimu, outraged);
	MSG(reimu, "Ascolta!! E' DIFFICILE trovare vestiti che posso indossare tutti i giorni al lavoro!"); 
	MSG(reimu, "Deve adattarsi a un certo stile!"); 
	MSG(reimu, "E solamente pochi tessuti sono comodi da indossare!"); 
	MSG(reimu, "Non sopporto la lana ruvida o la seta scivolosa!"); 
	MSG(reimu, "Tutto il resto è di nuovo terribile, la mia pelle—"); 
	FACE(reimu, irritated);
	MSG(reimu, "… Accidenti! Ora sono irritata!"); 

	EVENT(music_changes);

	MSG(reimu, "Odio gli abitanti delle dimore perfette!"); 
	FACE(reimu, outraged);
	MSG(reimu, "Facciamola finita!"); 

	DIALOG_END();
}

DIALOG_TASK(reimu, Stage4PostBoss) {
	DIALOG_BEGIN(Stage4PostBoss);

	ACTOR_LEFT(reimu);
	ACTOR_RIGHT(kurumi);
	VARIANT(kurumi, defeated);
	FACE(kurumi, defeated);

	FACE(reimu, irritated);
	MSG(reimu, "Questo è per aver insultato il mio abbigliamento in quel modo."); 

	MSG(kurumi, "Ahi Ahi Ahi…"); 
	MSG(kurumi, "A-aspetta, cosa è successo?"); 

	MSG(reimu, "In che senso ‘cosa è successo’?"); 

	MSG(kurumi, "(F-forse se fingo di avere un'amnesia… sì, è così…!)"); 
	FACE(kurumi, normal);
	MSG(kurumi, "O-oh, la mia testa! Ahi! Come sono arrivata qui???"); 
	MSG(kurumi, "A-aspetta! Non sei quella ragazza di tanto tempo fa?"); 

	FACE(reimu, unsettled);
	MSG(reimu, "Perché non mi ricordo affatto di te? È solo quella sensazione inquietante di nuovo…");
	MSG(reimu, "E' familiare…");
	FACE(reimu, sigh);
	MSG(reimu, "È fastidioso, qualunque cosa sia. Fallo smettere, o dimmi come farlo smettere.");

	FACE(kurumi, defeated);
	MSG(kurumi, "Eh? N-non lo so! Non mi ricordo nulla!"); 
	MSG(kurumi, "(Ugh, i suoi vestiti fanno davvero schifo però…)"); 

	MSG(reimu, "(Solo un altra vittima…?)");
	FACE(reimu, normal);
	MSG(reimu, "Rimani da queste parti. Voglio parlarti dopo aver sistemato la cosa.");

	DIALOG_END();
}

/*
 * Stage 5
 */

DIALOG_TASK(reimu, Stage5PreBoss) {
	DIALOG_BEGIN(Stage5PreBoss);

	ACTOR_LEFT(reimu);
	ACTOR_RIGHT(iku);
	HIDE(iku);

	FACE(reimu, unsettled);
	MSG(reimu, "Ho un brutto presentimento a riguardo…"); 
	FACE(reimu, puzzled);
	MSG(reimu, "O forse mi sento solo nauseata dal costante girare di questa torre."); 

	EVENT(boss_appears);
	WAIT(60);
	SHOW(iku);
	FACE(iku, normal);
	MSG(iku, "O forse è un effetto collaterale della mera presenza della torre?"); 

	MSG(reimu, "Oh, sei tu. Perché mi hai attaccata prima, comunque?"); 

	TITLE(iku, "Nagae Iku", "Fulminologa dei cieli"); 
	FACE(iku, smile);
	MSG(iku, "Ah, scusa. Dev'essere stato fuoco amico."); 
	FACE(iku, eyes_closed);
	MSG(iku, "le cose sono piuttosto frenetiche qui. Mi auguro che comprenda."); 
	MSG(iku, "Ne è passato di tempo dall'ultima volta, vero?"); 

	FACE(reimu, normal);
	MSG(reimu, "Ehm, già è passato un po' di tempo. Che bello rivederti."); 

	FACE(iku, serious);
	MSG(iku, "Andiamo dritto al punto, questa torre è diversa da qualsiasi cosa vista prima d'ora."); 
	MSG(iku, "Da quando si è sparsa la voce tra le nuvole, ho appreso che il colpevole è collegato a degli ‘universi paralleli.");

	FACE(reimu, puzzled);
	MSG(reimu, "Intendi tipo l'Altro Mondo? Non è troppo fuori dall'ordinario di questi tempi."); 
	FACE(reimu, unsettled);
	MSG(reimu, "Qua sembra diverso però. È come se i muri stessero risucchiando la fede nel vuoto."); 
	MSG(reimu, "Sono soprpresa riguardo alla sopravvivenza delle fate…"); 
	FACE(reimu, normal);
	MSG(reimu, "Ma cosa ci fai qui?"); 

	FACE(iku, eyes_closed);
	MSG(iku, "Non sono solo gli Inferi e Gensōkyō ad essere colpiti"); 
	FACE(iku, serious);
	MSG(iku, "In Bhava-agra, anche la personalità della figlia maggiore ha subito alcuni cambiamenti."); 

	FACE(reimu, surprised);
	MSG(reimu, "si sta diffondendo così velocemente?!"); 

	FACE(iku, smile);
	MSG(iku, "Inizialmente, non avevo intenzione di interferire."); 
	FACE(reimu, normal);
	FACE(iku, serious);
	MSG(iku, "Tuttavia, gli effetti psicologici della torre iniziarono a intensificarsi e cominciai a temere che nessuno si sarebbe fatto carico.");

	FACE(reimu, sigh);
	MSG(reimu, "(La gente ha così poca fiducia in me?)"); 

	FACE(iku, eyes_closed);
	MSG(iku, "Man mano che più menti cominciavano a divenire prede, ho preso in considerazione una teoria…"); 
	FACE(reimu, normal);
	MSG(iku, "Questa macchina è incompatibile con l'esistenza della fantasia?");
	FACE(iku, normal);
	MSG(iku, "Questo potrebbe essere il motivo per cui provi un senso di terrore per il posto."); 

	FACE(reimu, normal);
	MSG(reimu, "Bene, questo lo risolve. Dov'è il proprietario, allora?");

	FACE(iku, smile);
	MSG(iku, "Sinceramente, non sono sicura che tu sia all'altezza del compito."); 
	MSG(iku, "Sei ancora relativamente composta, ma il tuo stato mentale sembra deteriorarsi."); 

	FACE(reimu, irritated);
	MSG(reimu, "Deteriorarsi? Ma sono appena arrivata!"); 

	EVENT(music_changes);
	MSG(iku, "Sei ancora così preoccupata. Dovresti tornare a casa prima di perderti."); 

	FACE(reimu, irritated);
	MSG(reimu, "No!");

	FACE(iku, serious);
	MSG(iku, "Mi scusi?"); 

	MSG(reimu, "Non ribadire il tuo pessimo parere nei miei confronti. Ne sono stufa!"); 
	FACE(reimu, assertive);
	MSG(reimu, "Darò a tutti un motivo per fidarvi di me!"); 

	MSG(iku, "Sembra che la tua determinazione sia incrollabile. Molto bene allora.");
	MSG(iku, "Permettimi di mettere alla prova la tua resistenza sulla loro macchina esasperante!"); 

	DIALOG_END();
}

DIALOG_TASK(reimu, Stage5PostMidBoss) {
	DIALOG_BEGIN(Stage5PostMidBoss);

	ACTOR_LEFT(reimu);
	FACE(reimu, surprised);

	// Dovrebbe essere solo un messaggio con un timeout fisso di 120 frame
	MSG_UNSKIPPABLE(reimu, 120, "Il pesce remo? Perché LEI è qui?"); 

	DIALOG_END();
}

DIALOG_TASK(reimu, Stage5PostBoss) {
	DIALOG_BEGIN(Stage5PostBoss);

	ACTOR_LEFT(reimu);
	ACTOR_RIGHT(iku);
	VARIANT(iku, defeated);
	FACE(iku, defeated);

	MSG(iku, "Ah…");
	MSG(iku, "Ho sbagliato a dubitare di te, suppongo."); 

	FACE(reimu, unamused);
	MSG(reimu, "In qualche modo non mi sento troppo soddisfatta da questo.");

	FACE(iku, eyes_closed);
	MSG(iku, "Ad essere onesta con te, sono contenta che tu sia arrivata dopo tutto.");
	MSG(iku, "Ora so che non sarei stata in grado di sconfiggerla.");
	FACE(reimu, normal);
	MSG(iku, "Dato che sei ancora in grado di pensare con chiarezza, forse Gensōkyō verrà salvato dopotutto."); 

	FACE(reimu, sigh);
	MSG(reimu, "Finalmente."); 
	FACE(reimu, normal);
	MSG(reimu, "Però hai ragione. Questa roba è più grande di Gensōkyō."); 
	MSG(reimu, "Dovrò prenderlo sul serio."); 

	FACE(iku, normal);
	MSG(iku, "Bene."); 
	MSG(iku, "Continua a salire fino a raggiungere l'ultimo piano. Lì incontrerai senza dubbio l'istigatore."); 

	DIALOG_END();
}

/*
 * Stage 6
 */

DIALOG_TASK(reimu, Stage6PreBoss) {
	DIALOG_BEGIN(Stage6PreBoss);

	ACTOR_LEFT(reimu);
	ACTOR_RIGHT(elly);
	HIDE(elly);
	EVENT(boss_appears);
	MSG_UNSKIPPABLE(elly, 180, "Bene bene bene. Sembra che un topo abbia violato la nostra proprietà."); 
	SHOW(elly);

	FACE(elly, smug);
	MSG(elly, "Che strano. Ormai dovresti aver perso la testa."); 

	FACE(reimu, unsettled);
	MSG(reimu, "Spegnilo e basta."); 
	MSG(reimu, "Non sono in vena di discutere, quindi non spingermi!"); 

	TITLE(elly, "Elly", "La mietitrice teorica"); 
	FACE(elly, angry);
	MSG(elly, "Audace da parte tua fare irruzione nella MIA torre e darmi ordini!"); 
	MSG(elly, "Ricordo ancora ciò che hai fatto a me e Lady Kazami!"); 

	FACE(reimu, sigh);
	MSG(reimu, "E cos'era quello, di nuovo?"); 
	MSG(reimu, "Sento una sensazione familiare solo guardandoti, però…"); 

	FACE(elly, shouting);
	MSG(elly, "È uno scherzo?! Stai cercando di prendermi in giro?!"); 

	FACE(reimu, assertive);
	MSG(reimu, "Penso che mi sarei ricordata di una torre gigante che fa impazzire le persone con il potere!");
	MSG(reimu, "Il minimo che puoi fare quando accusi qualcuno è dirgli quello che presumibilmente ha fatto!"); 

	FACE(elly, smug);
	MSG(elly, "Ah, capisco."); 
	MSG(elly, "Va bene. Lo dirò."); 
	FACE(elly, normal);
	FACE(reimu, unamused);
	MSG(elly, "Questa torre è un'invenzione recente. La sua mera esistenza è rivoluzionaria in diversi campi scientifici."); 
	MSG(elly, "La gente di questo Gensōkyō dovrebbe esserne grata per la sua vasta conoscenza scientifica…"); 
	MSG(elly, "Ma ahimé, abbiamo altri piani."); 

	FACE(reimu, unamused);
	MSG(reimu, "In qualche modo, sembra più una punizione."); 
	MSG(reimu, "Hai mai sentito il detto ‘L'ignoranza è beatitudine’?"); 
	MSG(reimu, "Non ci sarà nessuno su cui governare, o qualsiasi altra cosa, se li fai perdere a tutti."); 

	MSG(elly, "La Torre di Babele è in grado di ‘illuminare’ chi ha la fortuna di trovarsi attorno ad essa."); 
	FACE(elly, smug);
	MSG(elly, "Chiunque non sia in grado di comprendere la sua genialità sarà portato alla pazzia."); 
	FACE(elly, shouting);
	MSG(elly, "Ma i residenti di questo Gensōkyō significano meno di niente per noi! Questa è semplicemente una punizione!");

	FACE(reimu, unsettled);
	MSG(reimu, "‘Questo’ Gensōkyō…?"); 
	MSG(reimu, "Questo è un ‘Universo parallelo’?"); 

	FACE(elly, normal);
	MSG(elly, "Hmm? Pensi che questo Gensōkyō lo sia?"); 

	FACE(reimu, irritated);
	MSG(reimu, "Dimmelo tu! Sei la megalomane!"); 
	FACE(reimu, assertive);
	MSG(reimu, "Do you hate me because some other Reimu did something? Is that it?"); 
	MSG(reimu, "Mi odi perché un' altra Reimu ha fatto qualcosa? È così?"); 
	FACE(reimu, irritated);
	MSG(reimu, "Per essere una ‘scienziata’, non hai molto senso!"); 

	FACE(elly, angry);
	MSG(elly, "Forse te ne sei semplicemente dimenticato, come hai fatto con tutti noi!"); 
	FACE(reimu, unamused);
	MSG(elly, "Solo i privilegiati, come Lady Kazami, ce l'hanno fatta! Il resto di noi era perso!"); 

	FACE(reimu, unsettled);
	MSG(reimu, "Intendi Kazami Yuuka? E suppongo… anche Alice?"); 
	MSG(reimu, "Ricordo quando ho incontrato Alice per la prima volta, e anche lei ha detto cose strane, proprio come te adesso.");
	FACE(reimu, unamused);
	MSG(reimu, "Lei però non andava in giro a minacciare tutti!"); 

	FACE(elly, angry);
	MSG(elly, "Non siamo stati così fortunati! E per par condicio, prenderemo il controllo di questo Gensōkyō!"); 
	MSG(elly, "Faremo in modo che non saremo MAI dimenticate!"); 

	FACE(reimu, sigh);
	MSG(reimu, "Anche in Gensōkyō, puoi essere dimenticata, eh?"); 
	MSG(reimu, "Che triste pensiero. Non c'è da stupirsi che se mi sento male solo a vedere questo posto!");
	FACE(reimu, assertive);
	MSG(reimu, "Spegnilo o essere dimenticata sarà l'ultima delle tue preoccupazioni!"); 

	EVENT(music_changes);
	FACE(elly, shouting);
	MSG(elly, "È troppo tardi per quello! Presto, tutta Gensōkyō verràilluminata!"); 
	FACE(reimu, unsettled);
	MSG(elly, "Non capisci, sacerdotessa pietosa? La scienza è un potere insondabile, superato da nulla!"); 
	MSG(elly, "Non verremo dimenticate da questo mondo, ad ogni costo!"); 

	DIALOG_END();
}

DIALOG_TASK(reimu, Stage6PreFinal) {
	DIALOG_BEGIN(Stage6PreFinal);

	ACTOR_LEFT(reimu);
	ACTOR_RIGHT(elly);
	VARIANT(elly, beaten);
	FACE(elly, shouting);
	FACE(reimu, assertive);
	MSG(reimu, "È così? Hai finalmente finito?"); 
	MSG(elly, "P-pensi che sia finita?! Il tempo della resa dei conti è su di te!"); 
	MSG(elly, "Guarda l'ultima verità dell'universo e trema!"); 

	DIALOG_END();
}

/*
 * Register the tasks
 */

#define EXPORT_DIALOG_TASKS_CHARACTER reimu
#include "export_dialog_tasks.inc.h"
