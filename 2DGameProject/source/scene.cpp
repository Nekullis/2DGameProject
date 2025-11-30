#include "DxLib.h"
#include "winmain.h"
#include "gamemain.h"
#include "scene.h"

Scene::Scene() 
{
	for (int i = 0; i < _PT_CHARA_ALLNUM_; i++) {
		_cgChara[i] = -1;
	}

	LoadDivGraph("res/player/PlayerMotion/待機/taiki_L_00000_sheet.png"	, 48, 48, 1, 600, 600,				&_cgChara[PT_PLAYER_STAND]);
	LoadDivGraph("res/player/PlayerMotion/待機/taiki_R_00000_sheet.png", 48, 48, 1, 600, 600,				&_cgChara[PT_PLAYER_STAND + 48]);
	LoadDivGraph("res/player/PlayerMotion/走り/run_L_00000_sheet.png", 8, 8, 1, 600, 600,					&_cgChara[PT_PLAYER_RUN]);
	LoadDivGraph("res/player/PlayerMotion/走り/run_R_00000_sheet.png", 8, 8, 1, 600, 600,					&_cgChara[PT_PLAYER_RUN + 8]);
	LoadDivGraph("res/player/PlayerMotion/ダメージ/damage_L_00000_sheet.png", 8, 8, 1, 600, 600,				&_cgChara[PT_PLAYER_DAMAGE]);
	LoadDivGraph("res/player/PlayerMotion/ダメージ/damage_R_00000_sheet.png", 8, 8, 1, 600, 600,				&_cgChara[PT_PLAYER_DAMAGE + 8]);
	LoadDivGraph("res/player/PlayerMotion/伏せる/huse_L_00000_sheet.png", 8, 8, 1, 600, 600,					&_cgChara[PT_PLAYER_SQUAT]);
	LoadDivGraph("res/player/PlayerMotion/伏せる/huse_R_00000_sheet.png", 8, 8, 1, 600, 600,					&_cgChara[PT_PLAYER_SQUAT + 8]);
	LoadDivGraph("res/player/PlayerMotion/立ち上がる/up_L_00000_sheet.png", 8, 8, 1, 600, 600,				&_cgChara[PT_PLAYER_GETUP]);
	LoadDivGraph("res/player/PlayerMotion/立ち上がる/up_R_00000_sheet.png", 8, 8, 1, 600, 600,				&_cgChara[PT_PLAYER_GETUP + 8]);
	LoadDivGraph("res/player/PlayerMotion/包丁投げる/throw_L_00000_sheet.png", 8, 8, 1, 600, 600,				&_cgChara[PT_PLAYER_THROW]);
	LoadDivGraph("res/player/PlayerMotion/包丁投げる/throw_R_00000_sheet.png", 8, 8, 1, 600, 600,				&_cgChara[PT_PLAYER_THROW + 8]);
	LoadDivGraph("res/player/PlayerMotion/武器ないときモーション/nonthrow_L_00000_sheet.png", 8, 8, 1, 600, 600,&_cgChara[PT_PLAYER_NO_THROW]);
	LoadDivGraph("res/player/PlayerMotion/武器ないときモーション/nonthrow_R_00000_sheet.png", 8, 8, 1, 600, 600,&_cgChara[PT_PLAYER_NO_THROW + 8]);
	LoadDivGraph("res/player/PlayerMotion/ロック解除/unrock_00000_sheet.png", 8, 8, 1, 600, 600,				&_cgChara[PT_PLAYER_UNLOCK]);
	LoadDivGraph("res/player/PlayerMotion/死亡/die_L_00000_sheet.png", 16, 16, 1, 600, 600,					&_cgChara[PT_PLAYER_DEATH]);
	LoadDivGraph("res/player/PlayerMotion/死亡/die_R_00000_sheet.png", 16, 16, 1, 600, 600,					&_cgChara[PT_PLAYER_DEATH + 16]);
	LoadDivGraph("res/player/PlayerMotion/歩き/walk_L2_00000_sheet.png", 16, 16, 1, 600, 600,				&_cgChara[PT_PLAYER_WALK]);
	LoadDivGraph("res/player/PlayerMotion/歩き/walk_R2_00000_sheet.png", 16, 16, 1, 600, 600,				&_cgChara[PT_PLAYER_WALK + 16]);
	LoadDivGraph("res/player/PlayerMotion/階段/stair_down_back_00000_sheet.png", 8, 8, 1, 600, 600,			&_cgChara[PT_PLAYER_STAIR]);
	LoadDivGraph("res/player/PlayerMotion/階段/stair_down_front_00000_sheet.png", 8, 8, 1, 600, 600,			&_cgChara[PT_PLAYER_STAIR + 8]);
	LoadDivGraph("res/player/PlayerMotion/階段/stair_up_back_00000_sheet.png", 8, 8, 1, 600, 600,			&_cgChara[PT_PLAYER_STAIR + 16]);
	LoadDivGraph("res/player/PlayerMotion/階段/stair_up_front_00000_sheet.png", 8, 8, 1, 600, 600,			&_cgChara[PT_PLAYER_STAIR + 24]);
	LoadDivGraph("res/player/PlayerMotion/歩き/walk_R_00000_sheet.png", 7, 7, 1, 600, 600,					&_cgChara[PT_PLAYER_STAIR + 32]);
	LoadDivGraph("res/player/PlayerMotion/歩き/walk_L_00000_sheet.png", 7, 7, 1, 600, 600,					&_cgChara[PT_PLAYER_STAIR + 39]);
	LoadDivGraph("res/player/PlayerMotion/階段/stair_down_front_00000_sheet.png", 8, 8, 1, 600, 600,			&_cgChara[PT_PLAYER_START_STAIR]); 

	//マグロ
	LoadDivGraph("res/enemy/tuna/a_tuna_sheet_test_2/tuna_normal_00000_sheet.png", 8, 8, 1, 1300, 700, &_cgChara[PT_ENEMY1_RUN]);
	LoadDivGraph("res/enemy/tuna/a_tuna_sheet_test_2/tuna_attack_00000_sheet.png", 8, 8, 1, 1300, 700, &_cgChara[PT_ENEMY1_ATTACK]);
	LoadDivGraph("res/enemy/tuna/a_tuna_sheet_test_2/tuna_turn_R_00000_sheet.png", 5, 5, 1, 1300, 700, &_cgChara[PT_ENEMY1_L_TURN]);
	LoadDivGraph("res/enemy/tuna/a_tuna_sheet_test_2/tuna_turn_L_00000_sheet.png", 5, 5, 1, 1300, 700, &_cgChara[PT_ENEMY1_R_TURN]);

	//イワシ
	LoadDivGraph("res/enemy/sardine/sardine_sheet_test/sardine_normal_00000_sheet.png", 8, 8, 1, 800, 400, &_cgChara[PT_ENEMY2_RUN]);
	LoadDivGraph("res/enemy/sardine/sardine_sheet_test/sardine_attack_00000_sheet.png", 8, 8, 1, 800, 400, &_cgChara[PT_ENEMY2_ATTACK]);
	LoadDivGraph("res/enemy/sardine/sardine_sheet_test/sardine_turn_R_00000_sheet.png", 4, 4, 1, 800, 400, &_cgChara[PT_ENEMY2_L_TURN]);
	LoadDivGraph("res/enemy/sardine/sardine_sheet_test/sardine_turn_L_00000_sheet.png", 4, 4, 1, 800, 400, &_cgChara[PT_ENEMY2_R_TURN]);
	LoadDivGraph("res/enemy/sardine/sardine_sheet_test/sardine_dead_00000_sheet.png", 8, 8, 1,	1900, 950, &_cgChara[PT_ENEMY2_DAMAGE]);


	//ゾンビイワシ
	LoadDivGraph("res/enemy/z_sardine/zombie_sheet_test/zombie_normal_1_sheet.png", 8, 8, 1, 1100, 900,		&_cgChara[PT_ENEMY3_RUN]);
	LoadDivGraph("res/enemy/z_sardine/zombie_sheet_test/zombie_attack_1_sheet.png", 8, 8, 1, 1100, 900,		&_cgChara[PT_ENEMY3_ATTACK]);
	LoadDivGraph("res/enemy/z_sardine/zombie_sheet_test/zombie_turn_R_1_sheet.png", 4, 4, 1, 1100, 900,		&_cgChara[PT_ENEMY3_L_TURN]);
	LoadDivGraph("res/enemy/z_sardine/zombie_sheet_test/zombie_turn_L_1_sheet.png", 4, 4, 1, 1100, 900,		&_cgChara[PT_ENEMY3_R_TURN]);
	LoadDivGraph("res/enemy/z_sardine/zombie_sheet_test/zombie_dead_00000_sheet.png", 7, 7, 1, 2300, 1600,	&_cgChara[PT_ENEMY3_DAMAGE]);

	LoadDivGraph("res/enemy/boss/歩き/boss_walk_L_00000_sheet.png", 16, 16, 1, 685, 685,					&_cgChara[PT_ENEMY4_UNDISCOVER_RUN]);
	LoadDivGraph("res/enemy/boss/歩き/boss_walk_R_00000_sheet.png", 16, 16, 1, 685, 685,					&_cgChara[PT_ENEMY4_UNDISCOVER_RUN + 16]);
	LoadDivGraph("res/enemy/boss/歩き/boss_walk_L_00000_sheet.png", 16, 16, 1, 685, 685,					&_cgChara[PT_ENEMY4_RUN]);
	LoadDivGraph("res/enemy/boss/歩き/boss_walk_R_00000_sheet.png", 16, 16, 1, 685, 685,					&_cgChara[PT_ENEMY4_RUN + 16]);
	LoadDivGraph("res/enemy/boss/斬る/boss_attack_L_00000_sheet.png", 16, 8, 2, 1100, 1100,				&_cgChara[PT_ENEMY4_ATTACK]);
	LoadDivGraph("res/enemy/boss/斬る/boss_attack_R_00000_sheet.png", 16, 16, 1, 1100, 1100,				&_cgChara[PT_ENEMY4_ATTACK + 16]);
	LoadDivGraph("res/enemy/boss/ダメージ/boss_damage_L_00000_sheet.png", 8, 8, 1, 800, 685,				&_cgChara[PT_ENEMY4_DAMAGE]);
	LoadDivGraph("res/enemy/boss/ダメージ/boss_damage_R_00000_sheet.png", 8, 8, 1, 800, 685,				&_cgChara[PT_ENEMY4_DAMAGE + 8]);
	LoadDivGraph("res/enemy/boss/投げる/boss_throw_L_00000_sheet.png", 16, 16, 1, 822, 685,				&_cgChara[PT_ENEMY4_THROW]);
	LoadDivGraph("res/enemy/boss/投げる/boss_throw_R_00000_sheet.png", 16, 16, 1, 822, 685,				&_cgChara[PT_ENEMY4_THROW + 16]);
	LoadDivGraph("res/enemy/boss/スタンポーズ/boss_stun_L.png", 1, 1, 1, 685, 685,							&_cgChara[PT_ENEMY4_STAN]);
	LoadDivGraph("res/enemy/boss/スタンポーズ/boss_stun_R.png", 1, 1, 1, 685, 685,							&_cgChara[PT_ENEMY4_STAN + 1]);
	LoadDivGraph("res/enemy/boss/スタンから立ち上がる/boss_up_L_00000_sheet.png", 8, 8, 1, 685, 685,		&_cgChara[PT_ENEMY4_RECOVERY_STAN]);
	LoadDivGraph("res/enemy/boss/スタンから立ち上がる/boss_up_R_00000_sheet.png", 8, 8, 1, 685, 685,		&_cgChara[PT_ENEMY4_RECOVERY_STAN + 8]);
	LoadDivGraph("res/enemy/boss/ロッカー斬る/boss_attack_back_00000_sheet.png", 16, 16, 1, 800, 1100,		&_cgChara[PT_ENEMY4_CUTLOCKER]);
	LoadDivGraph("res/enemy/boss/階段/boss_stair_down_back_00000_sheet.png", 8, 8, 1, 685, 685,			&_cgChara[PT_ENEMY4_STAIR]);
	LoadDivGraph("res/enemy/boss/階段/boss_stair_down_front_00000_sheet.png", 8, 8, 1, 685, 685,			&_cgChara[PT_ENEMY4_STAIR + 8]);
	LoadDivGraph("res/enemy/boss/階段/boss_stair_up_back_00000_sheet.png", 8, 8, 1, 685, 685,			&_cgChara[PT_ENEMY4_STAIR + 16]);
	LoadDivGraph("res/enemy/boss/階段/boss_stair_up_front_00000_sheet.png", 8, 8, 1, 685, 685,			&_cgChara[PT_ENEMY4_STAIR + 24]);
	LoadDivGraph("res/enemy/boss/歩き/boss_walk_L_00000_sheet (1).png", 7, 16, 1, 685, 685,				&_cgChara[PT_ENEMY4_STAIR + 32]);
	LoadDivGraph("res/enemy/boss/歩き/boss_walk_R_00000_sheet.png", 7, 16, 1, 685, 685,					&_cgChara[PT_ENEMY4_STAIR + 39]);

	LoadDivGraph("res/enemy/school_of_fish_1/school_of_fish_00000_sheet.png", 8, 2, 4, 400, 450,		&_cgChara[PT_ENEMY5_RUN]);

	LoadDivGraph("res/gimmick/stage1/door1_1.png", 1, 1, 1, 365, 615,		&_cgChara[PT_GIMMICK_DOOR]);
	LoadDivGraph("res/gimmick/stage1/dooropen1.png", 5, 5, 1, 365, 615,		&_cgChara[PT_GIMMICK_OPEN_DOOR]);
	LoadDivGraph("res/gimmick/stage1/door1_5.png", 1, 1, 1, 365, 615,		&_cgChara[PT_GIMMICK_OPEN_DOOR+5]);
	LoadDivGraph("res/gimmick/stage1/doorclose1.png", 5, 5, 1, 365, 615,	&_cgChara[PT_GIMMICK_CLOSE_DOOR]);

	LoadDivGraph("res/gimmick/stage1/door_off1_1.png", 1, 1, 1, 365, 615,		&_cgChara[PT_GIMMICK_OFF_DOOR]);
	LoadDivGraph("res/gimmick/stage1/dooropen_off1.png", 5, 5, 1, 365, 615,		&_cgChara[PT_GIMMICK_OPEN_OFF_DOOR]);
	LoadDivGraph("res/gimmick/stage1/door_off1_5.png", 1, 1, 1, 365, 615,		&_cgChara[PT_GIMMICK_OPEN_OFF_DOOR + 5]);
	LoadDivGraph("res/gimmick/stage1/doorclose_off1.png", 5, 5, 1, 365, 615,	&_cgChara[PT_GIMMICK_CLOSE_OFF_DOOR]);

	LoadDivGraph("res/gimmick/pc.off.png", 1, 1, 1, 300, 500,	 &_cgChara[PT_GIMMICK_PC]);
	LoadDivGraph("res/gimmick/pc.lock.png", 1, 1, 1, 300, 500,	 &_cgChara[PT_GIMMICK_OPEN_PC]);
	LoadDivGraph("res/gimmick/pc.clear.png", 1, 1, 1, 300, 500,	 &_cgChara[PT_GIMMICK_CLOSE_PC]);

	LoadDivGraph("res/gimmick/stage3/pc3_off.png", 1, 1, 1, 300, 500,	&_cgChara[PT_GIMMICK_ESCAPE_PC]);
	LoadDivGraph("res/gimmick/stage3/pc3.png", 1, 1, 1, 300, 500,		&_cgChara[PT_GIMMICK_ESCAPE_OPEN_PC]);
	LoadDivGraph("res/gimmick/stage3/pc3_clear.png", 1, 1, 1, 300, 500, &_cgChara[PT_GIMMICK_ESCAPE_CLOSE_PC]);

	LoadDivGraph("res/gimmick/cage1.png", 1, 1, 1, 700, 700, &_cgChara[PT_GIMMICK_CAGE]);
	LoadDivGraph("res/gimmick/cage2.png", 1, 1, 1, 700, 700, &_cgChara[PT_GIMMICK_OPEN_CAGE]);

	LoadDivGraph("res/gimmick/stairs1.png", 1, 1, 1, 780, 1008, &_cgChara[PT_GIMMICK_STAIR]);
	LoadDivGraph("res/gimmick/stairs2.png", 1, 1, 1, 780, 1008, &_cgChara[PT_GIMMICK_STAIR_UP]);
	LoadDivGraph("res/gimmick/stairs2.png", 1, 1, 1, 780, 1008, &_cgChara[PT_GIMMICK_STAIR_DOWN]);

	LoadDivGraph("res/gimmick/stage3/elevator_off.png", 1, 1, 1, 724, 961,	&_cgChara[PT_GIMMICK_ELEVATOR]);
	LoadDivGraph("res/gimmick/stage3/erebe-ta-2.png", 1, 1, 1, 724, 961,	&_cgChara[PT_GIMMICK_OPEN_ELEVATOR]);
	LoadDivGraph("res/gimmick/stage3/erebe-ta-2.png", 1, 1, 1, 724, 961,	&_cgChara[PT_GIMMICK_EVENT_ELEVATOR]);

	LoadDivGraph("res/gimmick/stage3/locker1.png", 1, 1, 1, 228, 670, &_cgChara[PT_GIMMICK_LOCKER]);
	LoadDivGraph("res/gimmick/stage3/locker2.png", 1, 1, 1, 228, 670, &_cgChara[PT_GIMMICK_OPEN_LOCKER]);
	LoadDivGraph("res/gimmick/stage3/locker3.png", 1, 1, 1, 228, 670, &_cgChara[PT_PLAYERGIMMICK_INLOCKER]);


	LoadDivGraph("res/effect/knifeEffect.png", 7, 7, 1, 150, 150,	&_cgChara[PT_EFFECT_KNIFE]);
	LoadDivGraph("res/effect/point.png", 12, 3, 4, 64, 64,			&_cgChara[PT_ITEM_POINT]);
	LoadDivGraph("res/effect/boss_stair.png", 1, 1, 1, 30, 30,		&_cgChara[PT_ITEM_POINT + 12]);

	_se[SE_PLAYER_WALK + 0] = LoadSoundMem("res/se/player/PC_walk_L1.wav");
	_se[SE_PLAYER_WALK + 1] = LoadSoundMem("res/se/player/PC_walk_L2.wav");
	_se[SE_PLAYER_WALK + 2] = LoadSoundMem("res/se/player/PC_walk_L3.wav");
	_se[SE_PLAYER_WALK + 3] = LoadSoundMem("res/se/player/PC_walk_R1.wav");
	_se[SE_PLAYER_WALK + 4] = LoadSoundMem("res/se/player/PC_walk_R2.wav");
	_se[SE_PLAYER_WALK + 5] = LoadSoundMem("res/se/player/PC_walk_R3.wav");
	_se[SE_PLAYER_THROW] = LoadSoundMem("res/se/player/PC_knife_throw.mp3");
	_se[SE_PLAYER_DEAD] = LoadSoundMem("res/se/player/PC_dead.wav");
	_se[SE_PLAYER_RUN] = LoadSoundMem("res/se/player/PC_run.mp3");
	_se[SE_PLAYER_STAIR + 0] = LoadSoundMem("res/se/player/PC_stairs_up_down1.wav");
	_se[SE_PLAYER_STAIR + 1] = LoadSoundMem("res/se/player/PC_stairs_up_down2.wav");
	_se[SE_PLAYER_DAMAGE + 0] = LoadSoundMem("res/se/player/PC_hit_fish.mp3");
	_se[SE_PLAYER_DAMAGE + 1] = LoadSoundMem("res/se/player/PC_hit_stab.mp3");
	_se[SE_PLAYER_DAMAGE + 2] = LoadSoundMem("res/se/player/PC_hit_meatcleaver.wav");
	_se[SE_PLAYER_HEARTBEAT + 0] = LoadSoundMem("res/se/player/player_heartbeats1.mp3");
	_se[SE_PLAYER_HEARTBEAT + 1] = LoadSoundMem("res/se/player/player_heartbeats2.mp3");
	_se[SE_PLAYER_HEARTBEAT + 2] = LoadSoundMem("res/se/player/player_heartbeats3.mp3");

	_se[SE_ENEMY1_WALK] = LoadSoundMem("res/se/enemy/tuna/TUNA_swim.mp3");
	_se[SE_ENEMY1_ATTACK] = LoadSoundMem("res/se/enemy/tuna/TUNA_attack.wav");
	_se[SE_ENEMY1_EVENT1] = LoadSoundMem("res/se/enemy/tuna/TUNA_event1.mp3");

	_se[SE_ENEMY2_ATTACK] = LoadSoundMem("res/se/enemy/sardine/SARDINE_ATTACK.wav");
	_se[SE_ENEMY2_DEAD] = LoadSoundMem("res/se/enemy/sardine/SARDINE_dead.wav");
	_se[SE_ENEMY2_TO_ZOMBIE] = LoadSoundMem("res/se/enemy/sardine/SARDINE_be_ZOMBIE.wav");

	_se[SE_ENEMY3_ATTACK] = LoadSoundMem("res/se/enemy/zombie/ZOMBIE_ATTACK.mp3");
	_se[SE_ENEMY3_DEAD] = LoadSoundMem("res/se/enemy/zombie/ZOMBIE_dead.wav");

	_se[SE_ENEMY4_WALK + 0] = LoadSoundMem("res/se/enemy/boss/MASTER_walk1.wav");
	_se[SE_ENEMY4_WALK + 1] = LoadSoundMem("res/se/enemy/boss/MASTER_walk2.wav");
	_se[SE_ENEMY4_WALK + 2] = LoadSoundMem("res/se/enemy/boss/MASTER_walk_dlag_edge.wav");
	_se[SE_ENEMY4_ATTACK] = LoadSoundMem("res/se/enemy/boss/MASTER_close_range_attack.wav");
	_se[SE_ENEMY4_DAMAGE] = LoadSoundMem("res/se/enemy/boss/MASTER_hit.wav");
	_se[SE_ENEMY4_THROW] = LoadSoundMem("res/se/enemy/boss/MASTER_long_range_attack.wav");
	_se[SE_ENEMY4_STAIR + 0] = LoadSoundMem("res/se/enemy/boss/MASTER_stairs_up_down1.wav");
	_se[SE_ENEMY4_STAIR + 1] = LoadSoundMem("res/se/enemy/boss/MASTER_stairs_up_down2.wav");
	_se[SE_ENEMY4_STAIR + 2] = LoadSoundMem("res/se/enemy/boss/MASTER_stairs_up_down3.wav");
	_se[SE_ENEMY4_STAIR + 3] = LoadSoundMem("res/se/enemy/boss/MASTER_stairs_up_down4.wav");

	_se[SE_ENEMY5_WALK] = LoadSoundMem("res/se/enemy/tuna/SCHOOL_OF_FISH.mp3");

	_se[SE_GIMMICK_COMPUTER] = LoadSoundMem("res/se/gimmick/GIMMICK_computer_unlock_once.mp3");
	_se[SE_GIMMICK_DOOR] = LoadSoundMem("res/se/gimmick/GIMMICK_door_open.wav");
	_se[SE_GIMMICK_DOOR + 1] = LoadSoundMem("res/se/gimmick/GIMMICK_door_close.wav");
	_se[SE_GIMMICK_CAGE] = LoadSoundMem("res/se/gimmick/GIMMICK_iron_door_unlock.wav");
	_se[SE_GIMMICK_ELEVATER] = LoadSoundMem("res/se/gimmick/GIMMICK_elevator_arrive.wav");

	_se[SE_ITEM_HEAL] = LoadSoundMem("res/se/item/ITEM_heal.mp3");
	_se[SE_ITEM_KEY] = LoadSoundMem("res/se/item/ITEM_key_get.mp3");
	_se[SE_ITEM_KNIFE] = LoadSoundMem("res/se/item/ITEM_knife_get.mp3");

	_se[SE_EVENT_ZOMBIE] = LoadSoundMem("res/se/gimmick/event_window.mp3");
	_se[SE_EVENT_ALERT] = LoadSoundMem("res/se/gimmick/event_buzzer.mp3");
	_se[SE_EVENT_CLOSECAGE] = LoadSoundMem("res/se/gimmick/event_cage.mp3");

	for (int i = 0; i < _SE_ALL_; i++)
	{
		ChangeVolumeSoundMem(120, _se[i]);
	}
}

Scene::~Scene() 
{
	// 何もしない
}

void Scene::Input() 
{
	// 何もしない
}

void Scene::Process() 
{
	// 何もしない
}

void Scene::Draw() 
{
	// 何もしない
}