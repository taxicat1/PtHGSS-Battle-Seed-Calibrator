#include <string.h>

#include "move_list.h"

const char* moveNames[] = {
	"---",
	"Pound",
	"Karate Chop",
	"DoubleSlap",
	"Comet Punch",
	"Mega Punch",
	"Pay Day",
	"Fire Punch",
	"Ice Punch",
	"ThunderPunch",
	"Scratch",
	"ViceGrip",
	"Guillotine",
	"Razor Wind",
	"Swords Dance",
	"Cut",
	"Gust",
	"Wing Attack",
	"Whirlwind",
	"Fly",
	"Bind",
	"Slam",
	"Vine Whip",
	"Stomp",
	"Double Kick",
	"Mega Kick",
	"Jump Kick",
	"Rolling Kick",
	"Sand-Attack",
	"Headbutt",
	"Horn Attack",
	"Fury Attack",
	"Horn Drill",
	"Tackle",
	"Body Slam",
	"Wrap",
	"Take Down",
	"Thrash",
	"Double-Edge",
	"Tail Whip",
	"Poison Sting",
	"Twineedle",
	"Pin Missile",
	"Leer",
	"Bite",
	"Growl",
	"Roar",
	"Sing",
	"Supersonic",
	"SonicBoom",
	"Disable",
	"Acid",
	"Ember",
	"Flamethrower",
	"Mist",
	"Water Gun",
	"Hydro Pump",
	"Surf",
	"Ice Beam",
	"Blizzard",
	"Psybeam",
	"BubbleBeam",
	"Aurora Beam",
	"Hyper Beam",
	"Peck",
	"Drill Peck",
	"Submission",
	"Low Kick",
	"Counter",
	"Seismic Toss",
	"Strength",
	"Absorb",
	"Mega Drain",
	"Leech Seed",
	"Growth",
	"Razor Leaf",
	"SolarBeam",
	"PoisonPowder",
	"Stun Spore",
	"Sleep Powder",
	"Petal Dance",
	"String Shot",
	"Dragon Rage",
	"Fire Spin",
	"ThunderShock",
	"Thunderbolt",
	"Thunder Wave",
	"Thunder",
	"Rock Throw",
	"Earthquake",
	"Fissure",
	"Dig",
	"Toxic",
	"Confusion",
	"Psychic",
	"Hypnosis",
	"Meditate",
	"Agility",
	"Quick Attack",
	"Rage",
	"Teleport",
	"Night Shade",
	"Mimic",
	"Screech",
	"Double Team",
	"Recover",
	"Harden",
	"Minimize",
	"Smokescreen",
	"Confuse Ray",
	"Withdraw",
	"Defense Curl",
	"Barrier",
	"Light Screen",
	"Haze",
	"Reflect",
	"Focus Energy",
	"Bide",
	"Metronome",
	"Mirror Move",
	"Selfdestruct",
	"Egg Bomb",
	"Lick",
	"Smog",
	"Sludge",
	"Bone Club",
	"Fire Blast",
	"Waterfall",
	"Clamp",
	"Swift",
	"Skull Bash",
	"Spike Cannon",
	"Constrict",
	"Amnesia",
	"Kinesis",
	"Softboiled",
	"Hi Jump Kick",
	"Glare",
	"Dream Eater",
	"Poison Gas",
	"Barrage",
	"Leech Life",
	"Lovely Kiss",
	"Sky Attack",
	"Transform",
	"Bubble",
	"Dizzy Punch",
	"Spore",
	"Flash",
	"Psywave",
	"Splash",
	"Acid Armor",
	"Crabhammer",
	"Explosion",
	"Fury Swipes",
	"Bonemerang",
	"Rest",
	"Rock Slide",
	"Hyper Fang",
	"Sharpen",
	"Conversion",
	"Tri Attack",
	"Super Fang",
	"Slash",
	"Substitute",
	"Struggle",
	"Sketch",
	"Triple Kick",
	"Thief",
	"Spider Web",
	"Mind Reader",
	"Nightmare",
	"Flame Wheel",
	"Snore",
	"Curse",
	"Flail",
	"Conversion2",
	"Aeroblast",
	"Cotton Spore",
	"Reversal",
	"Spite",
	"Powder Snow",
	"Protect",
	"Mach Punch",
	"Scary Face",
	"Faint Attack",
	"Sweet Kiss",
	"Belly Drum",
	"Sludge Bomb",
	"Mud-Slap",
	"Octazooka",
	"Spikes",
	"Zap Cannon",
	"Foresight",
	"Destiny Bond",
	"Perish Song",
	"Icy Wind",
	"Detect",
	"Bone Rush",
	"Lock-On",
	"Outrage",
	"Sandstorm",
	"Giga Drain",
	"Endure",
	"Charm",
	"Rollout",
	"False Swipe",
	"Swagger",
	"Milk Drink",
	"Spark",
	"Fury Cutter",
	"Steel Wing",
	"Mean Look",
	"Attract",
	"Sleep Talk",
	"Heal Bell",
	"Return",
	"Present",
	"Frustration",
	"Safeguard",
	"Pain Split",
	"Sacred Fire",
	"Magnitude",
	"DynamicPunch",
	"Megahorn",
	"DragonBreath",
	"Baton Pass",
	"Encore",
	"Pursuit",
	"Rapid Spin",
	"Sweet Scent",
	"Iron Tail",
	"Metal Claw",
	"Vital Throw",
	"Morning Sun",
	"Synthesis",
	"Moonlight",
	"Hidden Power",
	"Cross Chop",
	"Twister",
	"Rain Dance",
	"Sunny Day",
	"Crunch",
	"Mirror Coat",
	"Psych Up",
	"ExtremeSpeed",
	"AncientPower",
	"Shadow Ball",
	"Future Sight",
	"Rock Smash",
	"Whirlpool",
	"Beat Up",
	"Fake Out",
	"Uproar",
	"Stockpile",
	"Spit Up",
	"Swallow",
	"Heat Wave",
	"Hail",
	"Torment",
	"Flatter",
	"Will-O-Wisp",
	"Memento",
	"Facade",
	"Focus Punch",
	"SmellingSalt",
	"Follow Me",
	"Nature Power",
	"Charge",
	"Taunt",
	"Helping Hand",
	"Trick",
	"Role Play",
	"Wish",
	"Assist",
	"Ingrain",
	"Superpower",
	"Magic Coat",
	"Recycle",
	"Revenge",
	"Brick Break",
	"Yawn",
	"Knock Off",
	"Endeavor",
	"Eruption",
	"Skill Swap",
	"Imprison",
	"Refresh",
	"Grudge",
	"Snatch",
	"Secret Power",
	"Dive",
	"Arm Thrust",
	"Camouflage",
	"Tail Glow",
	"Luster Purge",
	"Mist Ball",
	"FeatherDance",
	"Teeter Dance",
	"Blaze Kick",
	"Mud Sport",
	"Ice Ball",
	"Needle Arm",
	"Slack Off",
	"Hyper Voice",
	"Poison Fang",
	"Crush Claw",
	"Blast Burn",
	"Hydro Cannon",
	"Meteor Mash",
	"Astonish",
	"Weather Ball",
	"Aromatherapy",
	"Fake Tears",
	"Air Cutter",
	"Overheat",
	"Odor Sleuth",
	"Rock Tomb",
	"Silver Wind",
	"Metal Sound",
	"GrassWhistle",
	"Tickle",
	"Cosmic Power",
	"Water Spout",
	"Signal Beam",
	"Shadow Punch",
	"Extrasensory",
	"Sky Uppercut",
	"Sand Tomb",
	"Sheer Cold",
	"Muddy Water",
	"Bullet Seed",
	"Aerial Ace",
	"Icicle Spear",
	"Iron Defense",
	"Block",
	"Howl",
	"Dragon Claw",
	"Frenzy Plant",
	"Bulk Up",
	"Bounce",
	"Mud Shot",
	"Poison Tail",
	"Covet",
	"Volt Tackle",
	"Magical Leaf",
	"Water Sport",
	"Calm Mind",
	"Leaf Blade",
	"Dragon Dance",
	"Rock Blast",
	"Shock Wave",
	"Water Pulse",
	"Doom Desire",
	"Psycho Boost",
	"Roost",
	"Gravity",
	"Miracle Eye",
	"Wake-Up Slap",
	"Hammer Arm",
	"Gyro Ball",
	"Healing Wish",
	"Brine",
	"Natural Gift",
	"Feint",
	"Pluck",
	"Tailwind",
	"Acupressure",
	"Metal Burst",
	"U-turn",
	"Close Combat",
	"Payback",
	"Assurance",
	"Embargo",
	"Fling",
	"Psycho Shift",
	"Trump Card",
	"Heal Block",
	"Wring Out",
	"Power Trick",
	"Gastro Acid",
	"Lucky Chant",
	"Me First",
	"Copycat",
	"Power Swap",
	"Guard Swap",
	"Punishment",
	"Last Resort",
	"Worry Seed",
	"Sucker Punch",
	"Toxic Spikes",
	"Heart Swap",
	"Aqua Ring",
	"Magnet Rise",
	"Flare Blitz",
	"Force Palm",
	"Aura Sphere",
	"Rock Polish",
	"Poison Jab",
	"Dark Pulse",
	"Night Slash",
	"Aqua Tail",
	"Seed Bomb",
	"Air Slash",
	"X-Scissor",
	"Bug Buzz",
	"Dragon Pulse",
	"Dragon Rush",
	"Power Gem",
	"Drain Punch",
	"Vacuum Wave",
	"Focus Blast",
	"Energy Ball",
	"Brave Bird",
	"Earth Power",
	"Switcheroo",
	"Giga Impact",
	"Nasty Plot",
	"Bullet Punch",
	"Avalanche",
	"Ice Shard",
	"Shadow Claw",
	"Thunder Fang",
	"Ice Fang",
	"Fire Fang",
	"Shadow Sneak",
	"Mud Bomb",
	"Psycho Cut",
	"Zen Headbutt",
	"Mirror Shot",
	"Flash Cannon",
	"Rock Climb",
	"Defog",
	"Trick Room",
	"Draco Meteor",
	"Discharge",
	"Lava Plume",
	"Leaf Storm",
	"Power Whip",
	"Rock Wrecker",
	"Cross Poison",
	"Gunk Shot",
	"Iron Head",
	"Magnet Bomb",
	"Stone Edge",
	"Captivate",
	"Stealth Rock",
	"Grass Knot",
	"Chatter",
	"Judgment",
	"Bug Bite",
	"Charge Beam",
	"Wood Hammer",
	"Aqua Jet",
	"Attack Order",
	"Defend Order",
	"Heal Order",
	"Head Smash",
	"Double Hit",
	"Roar of Time",
	"Spacial Rend",
	"Lunar Dance",
	"Crush Grip",
	"Magma Storm",
	"Dark Void",
	"Seed Flare",
	"Ominous Wind",
	"Shadow Force"
};

int moveGetByName(const char* name) {
	for (int i = 1; i < NUM_MOVES; i++) {
		if (strcmp(name, moveNames[i]) == 0) {
			return i;
		}
	}
	
	return -1;
}
