/*
 * This software is licensed under the terms of the MIT License.
 * See COPYING for further information.
 * ---
 * Copyright (c) 2011-2019, Lukas Weber <laochailan@web.de>.
 * Copyright (c) 2012-2019, Andrei Alexeyev <akari@taisei-project.org>.
 */

#include "taisei.h"

#include "events.h"
#include "resource/resource.h"
#include "taisei.h"

#include "charprofile.h"
#include "mainmenu.h"
#include "portrait.h"
#include "common.h"
#include "progress.h"
#include "options.h"
#include "global.h"
#include "portrait.h"
#include "util/glm.h"
#include "video.h"

#define DESCRIPTION_WIDTH (SCREEN_W / 3 + 80)
#define FACES(...) { __VA_ARGS__, NULL }
#define NUM_FACES 12

typedef enum {
	PROFILE_REIMU,
	PROFILE_MARISA,
	PROFILE_YOUMU,
	PROFILE_CIRNO,
	PROFILE_HINA,
	PROFILE_SCUTTLE,
	PROFILE_WRIGGLE,
	PROFILE_KURUMI,
	PROFILE_IKU,
	PROFILE_ELLY,
	PROFILE_LOCKED,
	NUM_PROFILES
} CharProfiles;

typedef struct CharacterProfile {
	const char *name;
	const char *fullname;
	const char *title;
	const char *description;
	const char *background;
	const char *faces[NUM_FACES];
	ProgressBGMID unlock;
} CharacterProfile;

typedef struct CharProfileContext {
	int8_t face;
} CharProfileContext;

static const CharacterProfile profiles[NUM_PROFILES] = {
	[PROFILE_REIMU] = {
		.name = "reimu",
		.fullname = "Hakurei Reimu",
		.title = "Fanciulla del Santuario della Fantasia",
		.description = "Specie: Umana\nArea di studio: letteratura (fiction)\n\nLa fanciulla del santuario incredibilmente particolare.\n\nSi sta prendendo una pausa dal suo fitto programma di lettura di romanzi per occuparsi di un incidente.\n\nPer lo più, ha una vaga sensazione di sentimentalismo per un'era passata.\n\nIndipendentemente da quando gli abitanti della Montagna Youkai si presentarono singhiozzando alla sua porta, non ha altra scelta che mettere giù il libro e entrare in azione.",
		.background = "reimubg",
		.faces = FACES("normal", "surprised", "unamused", "happy", "sigh", "smug", "puzzled", "assertive", "irritated", "outraged"),
	},
	[PROFILE_MARISA] = {
		.name = "marisa",
		.fullname = "Kirisame Marisa",
		.title = "La Strega Incredibilmente Ordinaria",
		.description = "Specie: Umana\nArea di studio: Eclettismo\n\nLa strega sicura di sé e iperattiva.\n\nCuriosa come sempre sui limiti della magia e sulla natura della realtà, e quando sente parlare di 'follia soprannaturale', la sua curiosità ha la meglio su di lei.\n\nMa forse è meglio non leggere questo 'grimorio'?\n\nNo che un avvertimento del genere l'avrebbe comunque fermata. Quindi, se ne va.",
		.background = "marisa_bombbg",
		.faces = FACES("normal", "surprised", "sweat_smile", "happy", "smug", "puzzled", "unamused", "inquisitive"),
	},
	[PROFILE_YOUMU] = {
		.name = "youmu",
		.fullname = "Konpaku Yōmu",
		.title = "Spadaccina tra i mondi",
		.description = "Species: Mezza-Umana, Mezza-Fantasma\nArea of Study: Scherma\n\nLa spadaccina dei mezzi-morti.\n\n“Mentre te giocavi, Io studiavo la lama” … è probabilmente quello che direbbe.\n\nTroppo seria su tutto e totalmente terrorizzata da (metà della) sua stessa esistenza.\n\nTuttavia, Lady Yuyuko le ha affidato una missione importante. Speriamo che non si faccia prendere la mano.",
		.background = "youmu_bombbg1",
		.faces = FACES("normal", "eeeeh", "embarrassed", "eyes_closed", "chuuni", "happy", "relaxed", "sigh", "smug", "surprised", "unamused"),
	},
	[PROFILE_CIRNO] = {
		.name = "cirno",
		.fullname = "Cirno",
		.title = "Fata dei ghiacci termodinamica",
		.description = "Specie: Fata\nArea di studio: Termodinamica\n\nLa fata del ghiaccio, amabilmente sciocca.\n\nForse è un po' insoddisfatta dopo i suoi recenti duelli con divinità segrete e fate infernali?\n\nConsiderate di andarci piano con lei.",
		.background = "stage1/cirnobg",
		.unlock = PBGM_STAGE1_BOSS,
		.faces = FACES("normal", "angry", "defeated"),
	},
	[PROFILE_HINA] = {
		.name = "hina",
		.fullname = "Kagiyama Hina",
		.title = "Dea della Pestilenza Giroscopica",
		.description = "Specie: Dea della Pestilenza\nArea di studio: Stabilizzazione giroscopica\n\nGuardiano del Monte Yōkai. Il suo momento angolare è fuori dal mondo!\n\nSembra terribilmente preoccupata per la vostra salute e sicurezza, al punto da essere piuttosto prepotente.\n\nSei abbastanza grande per decidere il tuo percorso di vita, però.",
		.unlock = PBGM_STAGE2_BOSS,
		.background = "stage2/spellbg2",
		.faces = FACES("normal", "concerned", "serious", "defeated"),
	},
	[PROFILE_SCUTTLE] = {
		.name = "scuttle",
		.fullname = "Scuttle",
		.title = "Ingegnere Agile Insetto",
		.description = "Specie: Scarabeo bombardiere\nArea di studio: Sviluppo 'Web' full-stack\n\nNon tutte le cose sono calcolabili e questo bug sembra insinuarsi in un punto decisivo del percorso verso il vero colpevole.\n\nLa maggior parte degli insetti non organizza grandi rivoluzioni, eppure la loro presenza è sufficiente a sconvolgere il corso degli eventi.",
		.unlock = PBGM_STAGE3_BOSS,
		.background = "stage3/spellbg1",
		.faces = FACES("normal"),
	},
	[PROFILE_WRIGGLE] = {
		.name = "wriggle",
		.fullname = "Wriggle Nightbug",
		.title = "Attivista per i diritti degli insetti",
		.description = "Specie: Insetto\nArea di studio: Socio-Entomologia evolutiva\n\nUn insetto luminoso - o era un insetto? - lontano dal suo solito territorio.\n\nRitiene che gli insetti abbiano perso il loro 'posto legittimo' nella storia, qualunque cosa significhi.\n\nSe pensa di avere un trattamento evolutivo svantaggioso, qualcuno dovrebbe parlarle dei trilobiti...",
		.unlock = PBGM_STAGE3_BOSS,
		.background = "stage3/spellbg2",
		.faces = FACES("normal", "calm", "outraged", "proud", "defeated"),
	},
	[PROFILE_KURUMI] = {
		.name = "kurumi",
		.fullname = "Kurumi",
		.title = "Flebotomista dell'alta società",
		.description = "Specie: Vampira\nArea di studio: Ematologia\n\nUn'esplosione vampirica dal passato. Non sa che Gensōkyō ha già nuovi succhiasangue in città?\n\nÈ brava a succhiare il sangue, ma il suo lavoro attuale è quello di guardiana e la sua vera passione è l'alta moda.\n\nTutti hanno molteplici attività collaterali al giorno d'oggi...",
		.unlock = PBGM_STAGE4_BOSS,
		.background = "stage4/kurumibg1",
		.faces = FACES("normal", "dissatisfied", "puzzled", "tsun", "tsun_blush", "defeated"),
	},
	[PROFILE_IKU] = {
		.name = "iku",
		.fullname = "Nagae Iku",
		.title = "Fulminologa dei cieli",
		.description = "Species: Pesce Remo\nArea di studio: Meteorologia (Fulminologia)\n\nMessaggera dalle nuvole e meteorologa dilettante.\n\nSembra che negli ultimi tempi abbia letto qualche libro di testo di psichiatria troppo datato.\n\nNonostante sia così formale e soffocante, sembra essere l'unica a sapere cosa sta succedendo.",
		.background = "stage5/spell_lightning",
		.unlock = PBGM_STAGE5_BOSS,
		.faces = FACES("normal", "smile", "serious", "eyes_closed", "defeated"),
	},
	[PROFILE_ELLY] = {
		.name = "elly",
		.fullname = "Elly",
		.title = "Il Mietitore teorico",
		.description = "Specie: Shinigami(?)\nArea di studio: Fisica teorica / Patologia forense (doppio titolo)\n\nUn po' arrabbiato per essere stato dimenticato.\n\nPare che si sia procurata un tutor nell''arte oscura' della fisica teorica. Il suo passatempo è la megalomania.\n\nLetteralmente in cima al mondo, senza curarsi di chi sta sotto di lei. Cerca di non lasciare che troppe pietre schiaccino gli innocenti yōkai sottostanti quando la sua Torre di Babele inizia a crollare.",
		.background = "stage6/spellbg_toe",
		.unlock = PBGM_STAGE6_BOSS1,
		.faces = FACES("normal", "eyes_closed", "angry", "shouting", "smug", "blush"),
	},
	[PROFILE_LOCKED] = {
		.name = "Bloccato",
		.fullname = "Bloccato",
		.title = "...",
		.description = "Non hai ancora sbloccato questo personaggio!",
		.unlock = PBGM_GAMEOVER,
		.background = "stage1/cirnobg",
		.faces = FACES("locked"),
	}
};

static int check_unlocked_profile(int i) {
	int selected = PROFILE_LOCKED;
	if(!profiles[i].unlock) {
		// for protagonists
		selected = i;
	} else if(profiles[i].unlock != PBGM_GAMEOVER) {
		if(progress_is_bgm_id_unlocked(profiles[i].unlock)) selected = i;
	}
	return selected;
}

static void charprofile_logic(MenuData *m) {
	dynarray_foreach(&m->entries, int i, MenuEntry *e, {
		e->drawdata += 0.05 * ((m->cursor != i) - e->drawdata);
	});
	MenuEntry *cursor_entry = dynarray_get_ptr(&m->entries, m->cursor);
	Font *font = res_font("small");
	char buf[512] = { 0 };
	int j = check_unlocked_profile(m->cursor);
	text_wrap(font, profiles[j].description, DESCRIPTION_WIDTH, buf, sizeof(buf));
	double height = text_height(font, buf, 0) + font_get_lineskip(font) * 2;

	fapproach_asymptotic_p(&m->drawdata[0], 1, 0.1, 1e-5);
	fapproach_asymptotic_p(&m->drawdata[1], 1 - cursor_entry->drawdata, 0.1, 1e-5);
	fapproach_asymptotic_p(&m->drawdata[2], height, 0.1, 1e-5);
}

static void charprofile_draw(MenuData *m) {
	assert(m->cursor < NUM_PROFILES);
	r_state_push();

	CharProfileContext *ctx = m->context;

	draw_main_menu_bg(m, SCREEN_W/4+100, 0, 0.1 * (0.5 + 0.5 * m->drawdata[1]), "menu/mainmenubg", profiles[m->cursor].background);
	draw_menu_title(m, "Character Profiles");


	// background behind description text
	float f = m->drawdata[0];
	float descbg_ofs = 100 + 30 * f - 20 * f - font_get_lineskip(res_font("small")) * 0.7;
	r_mat_mv_push();
	r_mat_mv_translate(SCREEN_W/4, SCREEN_H/3, 0);
	r_color4(0, 0, 0, 0.5);
	r_shader_standard_notex();
	r_mat_mv_translate(-120, descbg_ofs + m->drawdata[2] * 0.5, 0);
	r_mat_mv_scale(650, m->drawdata[2], 1);
	r_draw_quad();
	r_shader_standard();
	r_mat_mv_pop();

	MenuEntry *e = dynarray_get_ptr(&m->entries, m->cursor);

	float o = 1 - e->drawdata*2;
	float pbrightness = 0.6 + 0.4 * o;

	float pofs = fmax(0.0f, e->drawdata * 1.5f - 0.5f);
	pofs = glm_ease_back_in(pofs);

	int selected = check_unlocked_profile(m->cursor);

	Color *color = RGBA(pbrightness, pbrightness, pbrightness, 1);

	// if not unlocked, darken the sprite so it's barely visible
	if(selected == PROFILE_LOCKED) {
		color = RGBA(0.0, 0.0, 0.0, 0.9);
	}

	Sprite *spr = e->arg;
	SpriteParams portrait_params = {
		.pos = { SCREEN_W/2 + 240 + 320 * pofs, SCREEN_H - spr->h * 0.5 },
		.sprite_ptr = spr,
		.shader = "sprite_default",
		.color = color,
	};

	r_draw_sprite(&portrait_params);

	if(selected != PROFILE_LOCKED) {
		portrait_params.sprite_ptr = portrait_get_face_sprite(profiles[selected].name, profiles[selected].faces[ctx->face]);
		r_draw_sprite(&portrait_params);
		text_draw_wrapped("Premere [Fuoco] per le espressioni alternative", DESCRIPTION_WIDTH, &(TextParams) {
			.align = ALIGN_LEFT,
			.pos = { 25, 570 },
			.font = "standard",
			.shader = "text_default",
			.color = RGBA(0.9, 0.9, 0.9, 0.9),
		});
	}

	r_mat_mv_push();
	r_mat_mv_translate(SCREEN_W/4, SCREEN_H/3, 0);
	r_mat_mv_push();
	r_mat_mv_push();

	if(e->drawdata != 0) {
		r_mat_mv_translate(0, -300 * e->drawdata, 0);
		r_mat_mv_rotate(M_PI * e->drawdata, 1, 0, 0);
	}

	text_draw(profiles[selected].fullname, &(TextParams) {
		.align = ALIGN_CENTER,
		.font = "big",
		.shader = "text_default",
		.color = RGBA(o, o, o, o),
	});
	r_mat_mv_pop();

	if(e->drawdata) {
		o = 1 - e->drawdata * 3;
	} else {
		o = 1;
	}

	text_draw(profiles[selected].title, &(TextParams) {
		.align = ALIGN_CENTER,
		.pos = { 20*(1-o), 30 },
		.shader = "text_default",
		.color = RGBA(o, o, o, o),
	});
	r_mat_mv_pop();

	text_draw_wrapped(profiles[selected].description, DESCRIPTION_WIDTH, &(TextParams) {
		.align = ALIGN_LEFT,
		.pos = { -175, 120 },
		.font = "small",
		.shader = "text_default",
		.color = RGBA(o, o, o, o),
	});
	r_mat_mv_pop();

	o = 0.3*sin(m->frames/20.0)+0.5;
	r_shader("sprite_default");

	r_draw_sprite(&(SpriteParams) {
		.sprite = "menu/arrow",
		.pos = { 30, SCREEN_H/3+10 },
		.color = RGBA(o, o, o, o),
		.scale = { 0.5, 0.7 },
	});

	r_draw_sprite(&(SpriteParams) {
		.sprite = "menu/arrow",
		.pos = { 30 + 340, SCREEN_H/3+10 },
		.color = RGBA(o, o, o, o),
		.scale = { 0.5, 0.7 },
		.flip.x = true,
	});

	r_state_pop();
}

static void action_show_character(MenuData *m, void *arg) {
	return;
}

static void add_character(MenuData *m, int i) {
	if(strcmp(profiles[i].name, "locked")) {
		log_debug("profili dei personaggi - aggiunta di personaggi: %s", profiles[i].name);
		Sprite *spr = portrait_get_base_sprite(profiles[i].name, NULL);
		MenuEntry *e = add_menu_entry(m, NULL, action_show_character, spr);
		e->transition = NULL;
	}
}

static void charprofile_free(MenuData *m) {
	free(m->context);
}

// TODO: add a better drawing animation for character selection
static bool charprofile_input_handler(SDL_Event *event, void *arg) {
	MenuData *m = arg;
	CharProfileContext *ctx = m->context;
	TaiseiEvent type = TAISEI_EVENT(event->type);

	if(type == TE_MENU_CURSOR_LEFT) {
		play_sfx_ui("generic_shot");
		m->cursor--;
		ctx->face = 0;
	} else if(type == TE_MENU_CURSOR_RIGHT) {
		play_sfx_ui("generic_shot");
		m->cursor++;
		ctx->face = 0;
	} else if(type == TE_MENU_ACCEPT) {
		if(check_unlocked_profile(m->cursor) != PROFILE_LOCKED) {
			play_sfx_ui("generic_shot");
			// show different expressions for selected character
			ctx->face++;
			if(!profiles[m->cursor].faces[ctx->face]) {
				ctx->face = 0;
			}
		}
	} else if(type == TE_MENU_ABORT) {
		play_sfx_ui("hit");
		close_menu(m);
	} else {
		return false;
	}

	m->cursor = (m->cursor % m->entries.num_elements) + m->entries.num_elements * (m->cursor < 0);

	return false;

}

void preload_charprofile_menu(void) {
	for(int i = 0; i < NUM_PROFILES-1; i++) {
		for(int f = 0; f < NUM_FACES; f++) {
			if(!profiles[i].faces[f]) {
				break;
			}
			portrait_preload_face_sprite(profiles[i].name, profiles[i].faces[f], RESF_PERMANENT);
		}
		portrait_preload_base_sprite(profiles[i].name, NULL, RESF_PERMANENT);
		preload_resource(RES_TEXTURE, profiles[i].background, RESF_PERMANENT);
	}
};

static void charprofile_input(MenuData *m) {
	events_poll((EventHandler[]){
		{ .proc = charprofile_input_handler, .arg = m },
		{ NULL }
	}, EFLAG_MENU);
}

MenuData *create_charprofile_menu(void) {
	MenuData *m = alloc_menu();

	preload_charprofile_menu();

	m->input = charprofile_input;
	m->draw = charprofile_draw;
	m->logic = charprofile_logic;
	m->end = charprofile_free;
	m->transition = TransFadeBlack;
	m->flags = MF_Abortable;

	CharProfileContext *ctx = calloc(1, sizeof(*ctx));
	m->context = ctx;

	for(int i = 0; i < NUM_PROFILES; i++) {
		add_character(m, i);
	}

	m->drawdata[1] = 1;

	return m;
}
