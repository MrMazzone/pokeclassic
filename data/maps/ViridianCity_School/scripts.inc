.set LOCALID_WOMAN, 1
.set LOCALID_LASS,  2

ViridianCity_School_MapScripts::
	.byte 0

ViridianCity_School_EventScript_Lass::
	lock
	faceplayer
	msgbox ViridianCity_School_Text_TryingToMemorizeNotes, MSGBOX_DEFAULT
	applymovement LOCALID_LASS, Common_Movement_WalkInPlaceFasterUp
	waitmovement 2
	release
	end

ViridianCity_School_Text_TryingToMemorizeNotes::
    .string "Whew! I'm trying to memorize all my\n"
    .string "notes.$"

ViridianCity_School_EventScript_Woman::
	lock
	faceplayer
	msgbox ViridianCity_School_Text_ReadBlackboardCarefully, MSGBOX_DEFAULT
	turnobject LOCALID_WOMAN, DIR_SOUTH
	waitmovement 1
	release
	end

ViridianCity_School_Text_ReadBlackboardCarefully::
    .string "Okay!\p"
    .string "Be sure to read what's on the\n"
    .string "blackboard carefully!$"

ViridianCity_School_EventScript_Notebook::
	lockall
	msgbox ViridianCity_School_Text_NotebookFirstPage, MSGBOX_DEFAULT
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
	msgbox ViridianCity_School_Text_NotebookSecondPage, MSGBOX_DEFAULT
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
	msgbox ViridianCity_School_Text_NotebookThirdPage, MSGBOX_DEFAULT
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
	msgbox ViridianCity_School_Text_NotebookFourthPage, MSGBOX_DEFAULT
	applymovement LOCALID_LASS, Common_Movement_WalkInPlaceFasterUp
	waitmovement 2
	msgbox ViridianCity_School_Text_HeyDontLookAtMyNotes, MSGBOX_DEFAULT
	releaseall
	end

ViridianCity_School_Text_TurnThePage::
    .string "Turn the page?$"

ViridianCity_School_Text_NotebookFirstPage::
    .string "Let's check out the notebook.\p"
    .string "First page…\p"
    .string "Poké Balls are used to catch\n"
    .string "Pokémon.\p"
    .string "Up to six Pokémon can be carried\n"
    .string "in your party.\p"
    .string "People who raise and battle\n"
    .string "with Pokémon are called Trainers.$"

ViridianCity_School_Text_NotebookSecondPage::
    .string "Second page…\p"
    .string "A healthy Pokémon may be hard to\n"
    .string "catch, so weaken it first.\p"
    .string "Poison, burn, or cause another\n"
    .string "status problem to weaken it.$"

ViridianCity_School_Text_NotebookThirdPage::
    .string "Third page…\p"
    .string "Pokémon Trainers seek others to\n"
    .string "engage in Pokémon battles.\p"
    .string "To Trainers, the taste of victory\n"
    .string "is sweet, indeed.\p"
    .string "Battles are constantly waged at\n"
    .string "Pokémon Gyms everywhere.$"

ViridianCity_School_Text_NotebookFourthPage::
    .string "Fourth page…\p"
    .string "The ultimate goal for all Pokémon\n"
    .string "Trainers is simple.\p"
    .string "It is to defeat the top eight\n"
    .string "Pokémon Gym Leaders.\p"
    .string "Do so to earn the right to face…\p"
    .string "The Elite Four of the Pokémon\n"
    .string "League!$"

ViridianCity_School_EventScript_StopReadingNotebook::
	releaseall
	end

ViridianCity_School_Text_HeyDontLookAtMyNotes::
    .string "Girl: Hey!\n"
    .string "Don't look at my notes!$"

ViridianCity_School_EventScript_Blackboard::
	lockall
	msgbox ViridianCity_School_Text_BlackboardListsStatusProblems
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_Text_BlackboardListsStatusProblems::
    .string "The blackboard lists Pokémon\n"
    .string "Status problems during battles.$"

ViridianCity_School_EventScript_ChooseBlackboardTopic::
	message ViridianCity_School_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 7, 1, MULTI_TRAINER_SCHOOL_WHITEBOARD, 3, FALSE
	switch VAR_RESULT
	case 0, ViridianCity_School_EventScript_ReadSleep
	case 1, ViridianCity_School_EventScript_ReadPoison
	case 2, ViridianCity_School_EventScript_ReadParalysis
	case 3, ViridianCity_School_EventScript_ReadBurn
	case 4, ViridianCity_School_EventScript_ReadFreeze
	case 5, ViridianCity_School_EventScript_ExitBlackboard
	case MULTI_B_PRESSED, ViridianCity_School_EventScript_ExitBlackboard
	end

ViridianCity_School_Text_ReadWhichTopic::
    .string "Which topic do you want to read?$"

ViridianCity_School_EventScript_ReadSleep::
	msgbox ViridianCity_School_Text_ExplainSleep
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_Text_ExplainSleep::
    .string "A Pokémon can't attack if it's\n"
    .string "asleep.\p"
    .string "Pokémon will stay asleep even\n"
    .string "after battles.\p"
    .string "Use Awakening to awaken one\n"
    .string "from sleep.$"

ViridianCity_School_EventScript_ReadBurn::
	msgbox ViridianCity_School_Text_ExplainBurn
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_Text_ExplainBurn::
    .string "A burn reduces Attack power.\n"
    .string "It also causes ongoing HP loss.\p"
    .string "A burn remains after a battle.\n"
    .string "Use Burn Heal to cure a burn.$"

ViridianCity_School_EventScript_ReadPoison::
	msgbox ViridianCity_School_Text_ExplainPoison
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_Text_ExplainPoison::
    .string "When poisoned, a Pokémon's health\n"
    .string "steadily drops.\p"
    .string "Poison lingers after battles.\n"
    .string "Use an Antidote to cure poison!$"

ViridianCity_School_EventScript_ReadFreeze::
	msgbox ViridianCity_School_Text_ExplainFreeze
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_Text_ExplainFreeze::
    .string "A frozen Pokémon becomes\n"
    .string "helplessly immobile.\p"
    .string "It stays frozen even after the\n"
    .string "battle ends.\p"
    .string "Use Ice Heal to thaw out the\n"
    .string "suffering Pokémon.$"

ViridianCity_School_EventScript_ReadParalysis::
	msgbox ViridianCity_School_Text_ExplainParalysis
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_Text_ExplainParalysis::
    .string "Paralysis reduces Speed and may\n"
    .string "prevent the Pokémon from moving.\p"
    .string "Paralysis remains after battles.\n"
    .string "Use Parlyz Heal for treatment.$"

ViridianCity_School_EventScript_ExitBlackboard::
	closemessage
	releaseall
	end

ViridianCity_School_EventScript_PokemonJournal::
	lock
	msgbox PokemonJournal_Text_SpecialFeatureProfOak
	release
	end

PokemonJournal_Text_SpecialFeatureProfOak::
	.string "Pokémon Journal\p"
	.string "Special Feature: Prof. Oak,\n"
	.string "the Pokémon Researcher!\p"
	.string "Prof. Oak reportedly lives with his\n"
	.string "grandchildren Daisy and {RIVAL}.$"

ViridianCity_School_EventScript_PokemonJournal2::
	lock
	msgbox PokemonJournal_Text_SpecialFeatureDaisyOak
	release
	end

PokemonJournal_Text_SpecialFeatureDaisyOak::
	.string "This is a Pokémon Journal from\n"
	.string "years ago…\p"
	.string "Pokémon Journal\n"
	.string "Contest Special!\p"
	.string "The Spring Pokémon Contest's\n"
	.string "Grand Champion is Daisy Oak of\l"
	.string "Pallet Town!$"
