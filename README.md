# Intro
This tool will let you calibrate for battle seed RNG manipulation in Pokemon PtHGSS retail. Battle seed manipulation can be used for catching Pokemon on the first ball, contracting Pokerus, manipulating Pickup items, etc. This does not work in Diamond and Pearl; they use an entirely different system of battle RNG.

In PtHGSS, battles get their own random seed which is determined as soon as the battle begins. This is the same process as hitting a target initial seed, except instead of clicking 'A' on the continue screen at a specific time, you click 'A' on some way to start a battle.

Hitting battle seeds is subject to the same parity quirk as hitting initial seeds. That is, you will only ever hit odd seeds or even seeds with a given setup. To switch between the two, you can do any of the usual methods: insert a Pokemon GBA game into slot 2, change the year, or click 'new game' on the continue screen followed by backing out and clicking continue.

A tool to obtain target battle seeds to manipulate Pickup can be found here: https://github.com/Real96/PtHGSSPickupItemsRNGTool

The calibration process uses Metronome, which can roll one of 411 different moves at random. To use this reliably, obtain any Pokemon with Metronome, and then delete the other moves it knows so it only has Metronome. This is required because Metronome cannot call any of the other moves the user knows. To obtain the Metronome user, in Platinum you can catch a Togepi on Route 230 with the PokeRadar, and in HeartGold/SoulSilver you can use the Togepi you obtain from the egg or catch a Clefairy in Mt. Moon.

# Procedure
Set up your timer with your target delay and target time, and note the "minutes before target"; you will have to alter the "target seconds" later depending upon the method you use to generate the wild encounter, but the minutes before target that you use will still be this initial number.

To generate the battle, you have two primary options:

1.	Honey

	Honey has a delay between clicking "use" and the battle being seeded of about 3.25 seconds. If you use Honey, you will need to set the "target seconds" field in your timer (EonTimer etc.) to 3 seconds before your actual target. Honey can simply be purchased in Platinum, but in HeartGold/SoulSilver you must obtain it from wild Combee, which can be encountered by using Headbutt on trees on Routes 5, 6, 7, 8, 11, 16, or 25, or Vermilion City, Celadon City, or Cerulean City.

2.	Sweet Scent

	Sweet Scent has the same effect as Honey, but due to the extra animation of the Pokemon using a field move, has a delay of about 5.4 seconds. Unlike Generation 3, the field move animation's duration does not depend on the length of the Pokemon's cry. If you use Sweet Scent, set your timer's "target seconds" to 5 seconds before your actual target.

Stand in the grass and press A on Honey's "use" or "Sweet Scent" respectively as the timer's second set of beeps go off, and start the battle. (Technically, Headbutt, a trainer battle, or a static encounter would also all work!)

Also important: black-screen pauses between menus will briefly cause the game to stop rendering new frames, and this will stop the delay from counting up. This can simply be calibrated for, but you *must* do the exact same menuing for each calibration attempt and attempt to hit your target. For example, your menuing steps may be continuing, closing the journal, then opening the item menu and using Honey. You must do this exact procedure without deviation for each attempt. Do not detour to open the party menu, or re-save the game such that the journal will no longer show up, etc.

To search for what seed you hit, start with +/- 1 second if you know you have set your timer's target seconds field appropriately. For any unknown menuing, +/- 200 delay is a good place to start.

In the battle, your Metronome user *must* go first. This means the opponent cannot have any priority move; Protect or Bide etc. included. Doing this in areas with low-level Pokemon (without Quick Attack/Bide) like Lake Verity or Kanto Route 2 is recommended. Click Metronome on turn 1 and enter the move it rolls into the tool. It will then output possible battle seeds that you hit.

Do 3-4 attempts at calibration and check the possible seeds you hit for some that are closely clustered together. If needed, adjust the calibrated delay of your timer by a small amount (+/- 10 or so) and then look for a corrspendingly early or late result in your possible list of hit seeds.

When you have an idea of what delay you are hitting, enter this in your timer's "delay hit" field and update the timer, then do another round or 3-4 Metronome attempts and make sure you are getting results that are close to your calibration target.

## Compiling

```
gcc main.c calendar_util.c  input_tool.c metronome.c move_list.c searcher.c target_time.c -o PtHGSS-Battle-Seed-Calibrator.exe -Ofast
```
