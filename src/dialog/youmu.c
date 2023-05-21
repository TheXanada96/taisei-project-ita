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

DIALOG_TASK(youmu, Stage1PreBoss) {
	DIALOG_BEGIN(Stage1PreBoss);

	ACTOR_LEFT(youmu);
	ACTOR_RIGHT(cirno);
	HIDE(cirno);

	FACE(youmu, happy);
	MSG(youmu, "Suppongo che la neve che cade possa essere bella quanto i fiori di ciliegio…"); 

	EVENT(boss_appears);
	MSG_UNSKIPPABLE(cirno, 180, "Ehi!"); 
	SHOW(cirno);

	MSG(cirno, "Sono più figa di te, quindi vattene dal mio lago!"); 
	FACE(youmu, unamused);
	MSG(youmu, "Vedo che hai abbastanza freddo, sì."); 
	FACE(youmu, smug);
	MSG(youmu, "Tendo ad evitare i duelli con chi è più debole di me, quindi apprezzerei se ti facessi da parte."); 

	TITLE(cirno, "Cirno", "Fata del ghiaccio termodinamica"); 
	MSG(cirno, "AH! Casomai TU dovresti farti da parte!"); 

	FACE(youmu, eyes_closed);
	MSG(youmu, "Suppongo che sia il momento migliore per praticare la mia Tecnica di Distruzione dei Fiocchi di Neve."); 

	EVENT(music_changes);
	FACE(cirno, angry);
	MSG(cirno, "Ma se ti trasformo in un fiocco di neve, dovrai tagliarti a metà!");

	DIALOG_END();
}

DIALOG_TASK(youmu, Stage1PostBoss) {
	DIALOG_BEGIN(Stage1PostBoss);

	ACTOR_LEFT(youmu);
	ACTOR_RIGHT(cirno);
	VARIANT(cirno, defeated);
	FACE(cirno, defeated);

	FACE(youmu, sigh);
	MSG(youmu, "Il freddo non va bene per lame così sottili…"); 

	MSG(cirno, "D-Dovresti stare attenta con q-quelli!");

	FACE(youmu, unamused);
	MSG(youmu, "Sì, è quello che stavo dicendo."); 

	DIALOG_END();
}

/*
 * Stage 2
 */

DIALOG_TASK(youmu, Stage2PreBoss) {
	DIALOG_BEGIN(Stage2PreBoss);

	ACTOR_LEFT(youmu);
	ACTOR_RIGHT(hina);
	HIDE(hina);

	FACE(youmu, normal);
	MSG(youmu, "Dunque questa è la Montagna Yōkai…"); 
	MSG(youmu, "Peccato, ho sentito dire che di solito è un posto piuttosto vivace."); 

	EVENT(boss_appears);
	MSG_UNSKIPPABLE(hina, 180, "Oh mio, chi è? Un nuovo volto?"); 
	SHOW(hina);
	MSG(hina, "E chi potresti essere, cara?"); 

	MSG(youmu, "Konpaku Youmu. Lady Yuyuko mi ha affidato una missione per indagare sul disturbo."); 
	FACE(youmu, eyes_closed);
	MSG(youmu, "Non devi preoccuparti. Sono solo di passaggio."); 

	TITLE(hina, "Kagiyama Hina", "Dea giroscopica della pestilenza"); 
	MSG(hina, "Non ho mai sentito parlare di questa ‘Lady Yuyuko’ di cui stai parlando, ma non posso lasciare che ciò accada."); 
	FACE(youmu, normal);
	FACE(hina, serious);
	MSG(hina, "Ragazze giovani come te non dovrebbero essere mandate a fare commissioni così pericolose!");

	FACE(youmu, embarrassed);
	MSG(youmu, "‘G-Giovane ragazza’?! Ti farò notare che sono un'esperta spadaccina-"); 
	MSG(youmu, "-Avendo imparato la mia tecnica per oltre *decenni*-"); 
	MSG(youmu, "—Oserei dire anche la migliore di Gensōkyō—"); 

	FACE(hina, normal);
	MSG(hina, "Aww... come sei carina! In nessun modo una come te potrebbe interessarsi di ciò."); 
	MSG(hina, "Sei sicuro che questa cosa della ‘spadaccina esperta’ non sia solo una sorta di fase adolescenziale?"); 

	FACE(youmu, unamused);
	MSG(youmu, "Non è una FASE, ma—");
	FACE(youmu, embarrassed);
	MSG(youmu, "…!!"); 

	EVENT(music_changes);

	DIALOG_END();
}

DIALOG_TASK(youmu, Stage2PostBoss) {
	DIALOG_BEGIN(Stage2PostBoss);

	ACTOR_LEFT(youmu);
	ACTOR_RIGHT(hina);
	VARIANT(hina, defeated);
	FACE(hina, defeated);

	MSG(hina, "Mi hai appena chiamata ‘mamma’…?"); 

	FACE(youmu, eyes_closed);
	MSG(youmu, "No");
	MSG(youmu, "Dev'essere la follia che ti ha sopraffatto."); 
	MSG(youmu, "Sì, decisamente."); 

	FACE(hina, normal);
	MSG(hina, "Mio, mio…~"); 

	FACE(youmu, unamused);
	MSG(youmu, "Non osare."); 

	DIALOG_END();
}

/*
 * Stage 3
 */

DIALOG_TASK(youmu, Stage3PreBoss) {
	DIALOG_BEGIN(Stage3PreBoss);

	ACTOR_LEFT(youmu);
	ACTOR_RIGHT(wriggle);
	HIDE(wriggle);
	FACE(youmu, relaxed);
	MSG(youmu, "Più mi addentro in questa foresta, più mi sento irrequieta."); 
	FACE(youmu, normal);
	MSG(youmu, "C'è qualcosa che non va."); 

	EVENT(boss_appears);
	MSG_UNSKIPPABLE(wriggle, 120, "Cosa c'è che non va?"); 
	SHOW(wriggle);
	MSG(wriggle, "Forse sei spaventata dalla nostra crescente e schiacciante popolazione?"); 

	FACE(youmu, eyes_closed);
	MSG(youmu, "Le cimici non mi riguardano al momento."); 

	FACE(wriggle, outraged);
	MSG(wriggle, "Oh, quindi tutti gli insetti sono ‘cimici’, eh? Vedo com'è!"); 
	TITLE(wriggle, "Wriggle Nightbug", "Attivista dei Diritti degli Insetti"); 
	MSG(wriggle, "Hai mai sentito parlare di coleotteri? Mosche? Si tratta di rispetto, lo sai!"); 

	FACE(youmu, normal);
	MSG(youmu, "Mi scuso, non volevo mancare di rispetto."); 
	FACE(youmu, eyes_closed);
	MSG(youmu, "Sono in missione per Lady Yuyuko. Devo porre fine a ciò che sta acusando il disturbo in quest'area"); 
	FACE(youmu, normal);
	MSG(youmu, "Dimmi tutto quello che sai."); 

	FACE(wriggle, proud);
	MSG(wriggle, "Ah, ora capisco."); 
	FACE(wriggle, calm);
	MSG(wriggle, "Il potere esercitato da un esercito di insetti giganti solleverebbe sicuramente qualche preoccupazione."); 
	FACE(wriggle, proud);
	MSG(wriggle, "In poche parole, vogliamo ripristinare il nostro legittimo posto nella storia!"); 
	MSG(wriggle, "È naturale che gli abitanti inferiori della montagna si innervosiscono di fronte al nostro dominio naturale."); 
	FACE(wriggle, calm);
	MSG(wriggle, "Le tue scuse sono accettate. Non temerai la nostra ira. Per ora."); 

	FACE(youmu, unamused);
	MSG(youmu, "… no, no, gli insetti da soli non causerebbero questo tipo di disturbo…"); 
	FACE(youmu, eyes_closed);
	MSG(youmu, "Tutto quello di cui sono capaci è rovinare il mio giardino ben curato."); 

	MSG(wriggle, "Hai appena detto di essere…"); 
	FACE(wriggle, outraged);
	MSG(wriggle, "… una giardiniera?!");

	EVENT(music_changes);

	FACE(youmu, puzzled);
	MSG(wriggle, "Hai mostrato il tuo vero volto"); 
	MSG(wriggle, "La mia luce brilla più luminosa che mai ora! Insegnerò il dovuto rispetto a questo umile usurpatore!"); 
	MSG(wriggle, "In modo che possiamo vivere al di sopra del tuo pollice verde una volta per tutte!"); 

	DIALOG_END();
}

DIALOG_TASK(youmu, Stage3PostBoss) {
	DIALOG_BEGIN(Stage3PostBoss);

	ACTOR_LEFT(youmu);
	ACTOR_RIGHT(wriggle);
	VARIANT(wriggle, defeated);
	FACE(wriggle, defeated);

	FACE(youmu, eyes_closed);
	MSG(youmu, "Conosci la leggenda del Tonbokiri?"); 
	MSG(youmu, "Si diceva che la sua lama potesse tagliare a metà gli insetti semplicemente atterrando su di essa."); 
	FACE(youmu, smug);
	MSG(youmu, "Senza dubbio, questo è ciò che è accaduto oggi"); 

	MSG(wriggle, "non è il passato che dicevo…"); 

	MSG(youmu, "Che sfortuna per te."); 
	FACE(youmu, chuuni);
	MSG(youmu, "Non preoccuparti. Porrò fine alla tua follia delirante e restituirò giustizia e ordine al—"); 
	FACE(youmu, eeeeh);
	MSG(youmu, "… ugh, è un po' troppo, anche per me, no?"); 

	MSG(wriggle, "Sembra giusto, Onestamente…"); 

	FACE(youmu, unamused);
	MSG(youmu, "…");

	DIALOG_END();
}

/*
 * Stage 4
 */

DIALOG_TASK(youmu, Stage4PreBoss) {
	DIALOG_BEGIN(Stage4PreBoss);

	ACTOR_LEFT(youmu);
	ACTOR_RIGHT(kurumi);
	HIDE(kurumi);

	MSG(youmu, "A-ha, ora devo essere vicina al vero ingresso."); 
	FACE(youmu, eyes_closed);
	MSG(youmu, "Questa torre… Lo sento già…"); 
	FACE(youmu, chuuni);
	MSG(youmu, "Può davvero essere una sfida degna delle mie capacità, finalmente?"); 

	EVENT(boss_appears);
	SHOW(kurumi);
	MSG(kurumi, "Questa villa è in realtà piuttosto trasandata. Mi aspettavo di meglio");
	FACE(youmu, relaxed);
	MSG(youmu, "Tu chi saresti?"); 

	TITLE(kurumi, "Kurumi", "Flebotomista dell'alta società"); 
	FACE(kurumi, tsun);
	MSG(kurumi, "Mah! Sono Kurumi, una rosa nera solitaria che affoga in un mare di cattivo gusto!"); 
	MSG(kurumi, "Faresti meglio a ricordartelo!"); 

	FACE(youmu, eyes_closed);
	MSG(youmu, "Forse lo farò."); 
	FACE(youmu, normal);
	MSG(youmu, "Sei una socia di questi… abitanti della villa-torre, allora?"); 

	MSG(kurumi, "Ovviamente no! Per chi mi prendi?!"); 
	MSG(kurumi, "In nessun MODO vorrei associarmi alla gente di questa villa!"); 
	MSG(kurumi, "Si vestono come se fossero usciti fuori da un anime scadente degli anni '80!"); 

	FACE(youmu, eyes_closed);
	MSG(youmu, "Si vestono come se fossero usciti fuori da un anime scadente degli anni 80!"); 
	FACE(youmu, puzzled);
	MSG(youmu, "…Cosa sarebbe un ‘anime degli anni 80’ se posso chiedere?"); 

	FACE(kurumi, normal);
	MSG(kurumi, "Non lo so, non me lo chiedere!"); 
	MSG(kurumi, "La signora nella torre ne parla molto, quindi dev'essere sicuramente qualcosa di orribile."); 

	FACE(youmu, unamused);
	MSG(youmu, "Non hai appena detto che non eri associata a loro?"); 

	MSG(kurumi, "Sì, ma stavo mentendo per vedere quanto eri credulona."); 

	FACE(youmu, embarrassed);
	MSG(youmu, "O-ovviamente. L-lo sapevo."); 
	FACE(youmu, normal);
	MSG(youmu, "Volevo vedere se saresti stata sincera.");
	FACE(youmu, eyes_closed);
	MSG(youmu, "La mia vera sfida è al di là di te. Fatti da parte."); 

	EVENT(music_changes);

	MSG(kurumi, "No. Hai un ballo con uno splendido vampiro in programma prima!"); 
	MSG(kurumi, "In guardia, meditabonda spadaccina!"); 

	DIALOG_END();
}

DIALOG_TASK(youmu, Stage4PostBoss) {
	DIALOG_BEGIN(Stage4PostBoss);

	ACTOR_LEFT(youmu);
	ACTOR_RIGHT(kurumi);
	VARIANT(kurumi, defeated);
	FACE(kurumi, defeated);

	FACE(youmu, eyes_closed);
	MSG(youmu, "Nonostante la tua tecnica inferiore, devo ringraziarti."); 
	MSG(youmu, "‘Ballare’ con te è stata una piacevole distrazione sulla strada per il completamento della mia missione."); 
	FACE(youmu, chuuni);
	MSG(youmu, "Di al tuo ‘superiore’ che sto venendo a prenderli."); 

	MSG(kurumi, "(Parla seriamente come un antieore dei manga…)"); 
	FACE(kurumi, normal);
	MSG(kurumi, "Ah, Allora okay!"); 
	FACE(kurumi, defeated);
	MSG(kurumi, "Sono comunque stufa di fare la guardia a questa villa inquietante e spettrale."); 

	FACE(youmu, unamused);
	MSG(youmu, "S-… spettrale?"); 

	FACE(kurumi, puzzled);
	MSG(kurumi, "…?");
	FACE(kurumi, normal);
	MSG(kurumi, "… Esatto! Pensavo che sarebbe stata tutta ‘scientifica’, ma poi l'hanno resa infestata, con fantasmi e roba del genere!"); 

	FACE(youmu, eeeeh);
	MSG(youmu, "F-…"); 
	MSG(youmu, "FANTASMI?!"); 

	MSG(kurumi, "Spaventosi fantasmi vendicativi! Provano pure ad ucciderti!"); 
	MSG(kurumi, "Ma sicuramente una spadaccina forte come te potrebbe farcela."); 

	FACE(youmu, embarrassed);
	MSG(youmu, "D-datti da fare! Niente mi ostacolerà!"); 

	MSG(kurumi, "(Hahaha, è proprio credulona.)"); 

	DIALOG_END();
}

/*
 * Stage 5
 */

DIALOG_TASK(youmu, Stage5PreBoss) {
	DIALOG_BEGIN(Stage5PreBoss);

	ACTOR_LEFT(youmu);
	ACTOR_RIGHT(iku);
	HIDE(iku);

	FACE(youmu, relaxed);
	MSG(youmu, "Incredibile. Davvero sbalorditivo."); 
	FACE(youmu, eyes_closed);
	MSG(youmu, "Sì, la battaglia finale si avvicina. Me lo sento."); 
	FACE(youmu, chuuni);
	MSG(youmu, "Sarà un duello leggendario? Uno che passerà alla storia di Gensōkyō?!");

	EVENT(boss_appears);
	MSG_UNSKIPPABLE(iku, 180, "Oh, la giardiniera degli Inferi?"); 
	SHOW(iku);
	MSG(iku, "Non mi sorprende vederti qua."); 
	MSG(iku, "La tua padrona è stata presa dalla presenza della torre, presumo?");

	FACE(youmu, normal);
	MSG(youmu, "Lady Yuyuko si trova in un luogo sicuro e segreto.");

	MSG(iku, "Il Tempio Hakurei, presumo?"); 

	FACE(youmu, surprised);
	MSG(youmu, "C-chi te l'ha detto?! Sei in combutta anche con loro?!"); 

	FACE(iku, smile);
	MSG(iku, "Certo che no, ma dove altro sarebbe stata in un momento come questo?"); 

	FACE(youmu, unamused);
	MSG(youmu, "Mah. Forse siamo diventati troppo prevedibili."); 
	MSG(youmu, "Sono qui per risolvere questa questione. Non devi più preoccuparti di questo."); 

	FACE(iku, normal);
	MSG(iku, "Al contrario, direi."); 
	TITLE(iku, "Nagae Iku", "Fulminologa dei cieli"); 
	FACE(youmu, normal);
	MSG(iku, "Ho deciso di fare delle ricerche per conto mio."); 
	MSG(iku, "Questa torre è controllata da una macchina…"); 
	FACE(iku, serious);
	MSG(iku, "… e gli effetti della macchina sembrano andare ben oltre i confini di Gensōkyō");

	FACE(youmu, normal);
	MSG(youmu, "Compreso il paradiso, presumo? Vedo."); 
	FACE(youmu, eyes_closed);
	MSG(youmu, "Non aver paura. Non permetterò a nulla di ostacolarmi."); 
	FACE(youmu, chuuni);
	MSG(youmu, "Konpaku Youmu, la più grande spadaccina mai vissuta e morta, risolverà questo incidente una volta per tutte!");

	FACE(iku, smile);
	MSG(iku, "Sembra che la macchina abbia gonfiato troppo anche il tuo ego, Spadaccina di Hakugyokurō."); 
	MSG(iku, "Non dovresti essere più prudente in questa situazione"); 

	FACE(youmu, eyes_closed);
	MSG(youmu, "Ego esagerato? Non ha senso."); 
	MSG(youmu, "Durante le mie recenti battaglie, ho raggiunto uno stato meditativo che la maggior parte dei maestri d'armi sogna solo!"); 
	FACE(youmu, chuuni);
	MSG(youmu, "Grazie a ciò, ho realizzato la vera forma della mia tecnica di sconfitta degli yōkai, precedentemente incompleta!"); 

	MSG(iku, "È così? Credi che questa ‘tecnica’ ti aiuterà a sconfiggere i mandanti senza sforzo?"); 

	FACE(youmu, sigh);
	MSG(youmu, "Altri dubbi da scettici ignoranti, vedo."); 
	FACE(youmu, chuuni);
	MSG(youmu, "Duelliamo in modo che io possa dimostrare in modo soddisfacente?!"); 

	FACE(iku, serious);
	MSG(iku, "Aspetta, non è quello che intendevo, semplicemente—"); 

	EVENT(music_changes);

	MSG(iku, "Ah, non ho tempo per queste sciocchezze!"); 
	MSG(iku, "Umani insolenti come te hanno bisogno di riabilitazione! Permettimi di somministrartene un po'!"); 

	MSG(youmu, "Finalmente! Testimone della forza travolgente del mio Rōkanken!"); 

	DIALOG_END();
}

DIALOG_TASK(youmu, Stage5PostMidBoss) {
	DIALOG_BEGIN(Stage5PostMidBoss);

	ACTOR_LEFT(youmu);
	FACE(youmu, smug);

	// should be only one message with a fixed 180-frames timeout
	MSG_UNSKIPPABLE(youmu, 180, "Un fulmine? Mah. Posso superarlo facilmente."); 

	DIALOG_END();
}

DIALOG_TASK(youmu, Stage5PostBoss) {
	DIALOG_BEGIN(Stage5PostBoss);

	ACTOR_LEFT(youmu);
	ACTOR_RIGHT(iku);
	VARIANT(iku, defeated);
	FACE(iku, defeated);

	FACE(youmu, eyes_closed);
	MSG(youmu, "Tutto secondo i piani."); 

	MSG(iku, "La tua logica è così contorta…"); 
	MSG(iku, "Ahimè, non può essere aiutato. Probabilmente sei stata colpita da prima del tuo arrivo."); 
	MSG(iku, "Non ho altra scelta che lasciarti passare, nonostante le mie riserve."); 
	MSG(iku, "Forse le intenzioni pure si nascondono dietro quel tuo ego."); 

	MSG(youmu, "E forse sono davvero impazzita. Che ne dici?"); 
	MSG(youmu, "La mia missione è cristallina:"); 
	FACE(youmu, chuuni);
	MSG(youmu, "… per portare a termine la missione di Lady Yuyuko e portare la pace a Gensōkyō e a tutti i regni collegati!"); 
	MSG(youmu, "Non devo fallire!");

	MSG(iku, "H-ho visto."); 
	MSG(iku, "Sali la scala. Lì ti aspetterà il colpevole."); 
	MSG(iku, "Sii preparata. La tecnologia che possiede proviene da un cosiddetto ‘universo parallelo’."); 
	MSG(iku, "È diverso da qualsiasi cosa che nessuno di noi abbia mai incontrato prima. Nenche io sono sicura dei suoi dettagli."); 

	FACE(youmu, eyes_closed);
	MSG(youmu, "Non temere, taglierò a metà la sua macchina infernale come un'erba invasiva."); 

	DIALOG_END();
}

/*
 * Stage 6
 */

DIALOG_TASK(youmu, Stage6PreBoss) {
	DIALOG_BEGIN(Stage6PreBoss);

	ACTOR_LEFT(youmu);
	ACTOR_RIGHT(elly);
	HIDE(elly);

	FACE(youmu, eyes_closed);
	MSG(youmu, "Ah."); 
	FACE(youmu, chuuni);
	MSG(youmu, "Ah-hahaha!");
	MSG(youmu, "Sì. Sì! E' Questo!"); 
	FACE(youmu, happy);
	MSG(youmu, "Questa è ovviamente l'arena drammatica per la battaglia finale!"); 

	EVENT(boss_appears);
	MSG_UNSKIPPABLE(elly, 180, "Niente sembra rallentarti, eh?"); 

	SHOW(elly);
	MSG(elly, "Sei un tale fastidio. Ma c'era da aspettarselo dalla gente di questo Gensōkyō."); 

	MSG(youmu, "E vedo che sei una maestra della spada, nientemeno che uno shinigami!"); 
	MSG(youmu, "Absolutely splendid!");

	TITLE(elly, "Elly", "La mietitrice teorica"); 
	MSG(elly, "Ah, non sono uno shinigami, soprattutto non adesso."); 

	FACE(youmu, eyes_closed);
	MSG(youmu, "La falce è un'arma piuttosto particolare, devi capire. Perdonami la presunzione."); 

	MSG(elly, "Capisco.  Facevo affidamento su questa falce come custode, nel vero Gensōkyō."); 
	FACE(elly, angry);
	MSG(elly, "Ora sarà il sigillo di una nuova era!"); 
	FACE(elly, shouting);
	MSG(elly, "Uno tra di noi ‘dimenticati’, regnerà!"); 

	MSG(youmu, "Un'arma così ingombrante... perché chiunque la scelga volentieri…"); 
	MSG(youmu, "O sei incredibilmente abile o incredibilmente sciocca.");
	FACE(youmu, chuuni);
	MSG(youmu, "Vorrei scoprirlo!"); 
	MSG(youmu, "Dopo il nostro duello, incontriamoci e discutiamo delle nostre tecniche!"); 

	FACE(elly, angry);
	MSG(elly, "Tecniche? Hah!"); 
	MSG(elly, "La vostra esistenza non significa niente per noi! E sono sicura che la nostra esistenza non significa niente per voi!"); 

	FACE(youmu, chuuni);
	MSG(youmu, "Al contrario, portatrice di falce!");
	MSG(youmu, "Hai creato un palcoscenico impeccabile per il nostro confronto finale."); 
	FACE(youmu, happy);
	MSG(youmu, "Davvero, uno dei migliori. Congratulazioni!"); 
	FACE(youmu, eyes_closed);
	MSG(youmu, "Ma prima, per favore, dimmi: qual è la tua missione? Che cosa desideri?");
	FACE(youmu, chuuni);
	MSG(youmu, "Per condividere questo… momento intimo, desidero sapere tutto di te.");

	FACE(elly, blush);
	MSG(elly, "…!");
	MSG(elly, "L-la nostra missione, è di—"); 

	FACE(elly, eyes_closed);
	MSG(elly, "…");
	FACE(elly, angry);
	MSG(elly, "… di vendicare i nostri amici d-dimenticati!"); 
	MSG(elly, "Creeremo una nuova era in Gensōkyō, dove i veri dimenticati potranno vivere un altro giorno!"); 
	MSG(elly, "Presto, gli abitanti di questa terra impazziranno oltre ogni comprensione e saranno maturi per la conquista!"); 
	FACE(youmu, eyes_closed);
	MSG(youmu, "Quindi desideri vendicare i tuoi compatrioti caduti… che nobile…"); 
	MSG(youmu, "Sento che mi commuove fino alle lacrime…"); 
	FACE(youmu, chuuni);
	MSG(youmu, "Ahimè, la mia missione, affidatami da Lady Yuyuko degli Inferi, è direttamente in conflitto con la tua!"); 
	MSG(youmu, "Non posso lasciarti far impazzire i miei compatrioti o di soggiogare la mia casa!"); 
	FACE(youmu, eyes_closed);
	MSG(youmu, "Forse, in un altro tempo e luogo, saremmo potute essere amiche!"); 

	FACE(elly, angry);
	MSG(elly, "E-Essere amico di voi gente senza cuore sarebbe un peccato! Non potrei mai!"); 

	FACE(youmu, chuuni);
	MSG(youmu, "Come sei tragica!"); 

	MSG(elly, "Il tuo obiettivo è diventare il grande ‘eroe’ di questo Gensōkyō, vero?"); 

	MSG(youmu, "Naturalmente! Non è diverso da te che desideri essere l'eroe del ‘tuo’ Gensōkyō!"); 
	MSG(youmu, "Non siamo così diverse, noi due."); 

	FACE(elly, smug);
	MSG(elly, "Il tuo coraggio è ammirabile, te lo riconosco."); 
	FACE(elly, angry);
	MSG(elly, "Ma c'è un enorme differenza tra noi, spadaccina."); 

	EVENT(music_changes);

	FACE(elly, shouting);
	FACE(youmu, normal);
	MSG(elly, "Perché io possiedo la conoscenza della scienza!"); 
	MSG(elly, "In un mondo pieno di magia come questo, la scienza e la razionalità tagliano gli avversari con una precisione senza pari!"); 
	MSG(elly, "Vediamo a cosa ti servono le spade quando cadi preda della vera illuminazione!"); 

	DIALOG_END();
}

DIALOG_TASK(youmu, Stage6PreFinal) {
	DIALOG_BEGIN(Stage6PreFinal);

	ACTOR_LEFT(youmu);
	ACTOR_RIGHT(elly);
	VARIANT(elly, beaten);
	FACE(elly, angry);

	FACE(youmu, chuuni);
	MSG(youmu, "Degno di nota! Mi hai spinta al 10% del mio vero potere!");

	MSG(elly, "Il tuo spregevole orgoglio sarà la tua rovina!"); 
	FACE(elly, shouting);
	MSG(elly, "Guarda il tuo giudizio davanti alla vera natura della realtà!"); 

	DIALOG_END();
}

/*
 * Register the tasks
 */

#define EXPORT_DIALOG_TASKS_CHARACTER youmu
#include "export_dialog_tasks.inc.h"
