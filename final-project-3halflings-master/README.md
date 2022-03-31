 # Adventurer Simulator
This is a copy of the original Adventure Simulator, as the original game is privated
Authors: **Marshall Jones** : https://github.com/Sockzzz, **Nicole Boie** : https://github.com/nicboi1, **Dakota Heredia** : https://github.com/dako06  

## 7/1/21

**Project Description**

Our project will be a game consisting of a character creation menu very similiar to how character creation works in DnD. Once the player 
finishes choosing their race, class etc, they will have additional preset stats. These stats will come into play during the combat phase of 
the game where random encounters are continously fought. The player will first roll for accuracy against the monster on a D20. 

If the player wins the roll, they will then have any predetermined damage stats (based on character creation choices) added to a random D6 roll. If the 
monster won the accuracy roll, the player may use one of their reroll charges to reroll once for that accuracy roll, the result of which is
final. Depending on how many attributes a player holds, determines the amount of reroll charges they possess during a fighting phase. More 
attributes will also modify a players predetermined damage, HP, and roll modifier, all of which is calculated behind the scenes away from the 
player.

Depending on the attributes influenced by the players decisions, additional modifiers can be applied to the roll such has a bonus roll. 
If the player wins then they may have full HP restored or gamble to add a new attribute at the cost of potentially losing another. The 
game ends when the player has 0 HP and their highscore will be displayed at the end. 

**Command Patterns**

This would incorporate abstract factory and state changing, and we will be coding in C++.
We anticapte that the game will take place in the terminal. 

**1. Abtract Factory** 

We will use abstract factory to make it easier to break down all the different classes and races. Without this we would have to pain stakingly repeat very similiar abstract design parameters for each class and race. By using abstract factory we are able to modify the attributes much easier. The two factories we will be implementing are a Monster factory and a Player factory. From the Monster factory we will instantiate a few distinct monster-like character's all sharing similar factory operations and attributes with the exception of a possible boss-level monster. A monster library class will be used as the client to request and maintain the monters. Likewise, the Player class will define some factory operations and attributes allowing the user to define their character and furthermore influence the distinct attributes of this unique build. The key makes will be the Race and Title features such as fighter, wizard, dwarf, human and so on.

**2. State Changing**

State design will be implemented by using a game controller class to request state changes from a Game State class. The Game State subclasses will implement different stages of the game flow, transitioning the player through: 

**greeting -> character creation -> combat -> combat resolve -> view score**

This eliminates the need for large  blocks of commonly used switch-based state design based on local control variables, while maintaing control flow. Within the Combat state, 
further detailed control will exist such as: 

**character roll -> monster roll -> reaction -> resolving turn -> character roll**

This will be implemented either by traditional state-machine design or an additional CombatState Class to handle the phases of the general combat state.  We decided to use this design pattern to help facilitate all the stages of the game that change the users interaction with it. By using state changing we can better control the behavior of the program and restrict the user's available actions for simplicity.   

**Why we are creating Adventure Simulator**

We all like games and wanted to try implementing a unique game of our own that pulls from our interests.

**Input and Output**

Input would be player decisions on the initial aspects of their character, further input would occur during combat if a player activated an attribute or at the end of combat when choosing a reward.
Output would be the outcome of player/monster rolls as well as their final score. 


## 7/8/21

## Kanban Board
https://github.com/cs100/final-project-3halflings/projects/1
![alt text](https://cdn.discordapp.com/attachments/858209303608950785/862069454039941140/kanban.PNG)


## Class Diagrams
https://lucid.app/lucidchart/719787fb-2984-4851-ab8e-a50bbf2c3edb/view?page=0_0#
![alt text](https://cdn.discordapp.com/attachments/858209303608950785/862069469585211432/mainChart.PNG)

 Abtract Factory Class Diagram Description
 
 -Title is inherited by Bard, Wizard, Ranger, Rogue, and Paladin. They all have specialized title names, hp modifier, and roll modifier.
 
 -Race is inherited by Elf, Dwarf, Human, and Halfling. They all have specialized race names and IDs, that will determine attributes.
 
 -Attribute is inherited by Att_Elf, Att_Dwarf, Att_Human, and Att_halfling. They contain the special effects each attribute has that a character can attain.
 
 -Attribute_List is a superior class to Attribute that holds and accesses the different attributes.
 
 -Race Stats accesses race and the attributes of the character.
 
 -Character is the main class which holds all the information that has to do with character creation.
 
 -Factory is an abstract class used as a abstract factory for creating both basic and boss monster objects which the user will fight. The MonsterFactory and BossMonsterFactory both inherit from Factory so that they can be used to automatically generate various monster objects within the game.
 
 ## 7/20
 ## Screenshots
 
 **Character Creation**
 
 ![Screen Shot 2021-07-20 at 11 41 08 AM](https://user-images.githubusercontent.com/86252234/126378868-e3d8d012-0fc1-4beb-87b8-9edf976e02f8.png)
 
 **Choosing Tite and Roll**
 
![Screen Shot 2021-07-20 at 11 42 51 AM](https://user-images.githubusercontent.com/86252234/126378883-e2b948d7-91ff-4d86-83ae-6db015b255bb.png)

**Entering Combat-Monster Created**

![Screen Shot 2021-07-20 at 11 43 02 AM](https://user-images.githubusercontent.com/86252234/126378898-d06d5f2c-7c05-44d0-bc4a-8f92eb1d79de.png)

**Reroll Option**

![Screen Shot 2021-07-20 at 11 43 44 AM](https://user-images.githubusercontent.com/86252234/126378912-5a789a30-b38c-437b-aff6-43cc1a2f9bb8.png)

**Roll and Conitnue Combat**

![Screen Shot 2021-07-20 at 11 44 09 AM](https://user-images.githubusercontent.com/86252234/126378934-a77096b8-3d44-4874-9ef0-a7816ddf7855.png)

**Beating the Monster-Reward Option**

![Screen Shot 2021-07-20 at 11 44 23 AM](https://user-images.githubusercontent.com/86252234/126378948-039bbc0f-011f-4f59-91ea-c0d324eeed1f.png)

**Start Combat Again**

![Screen Shot 2021-07-20 at 11 44 40 AM](https://user-images.githubusercontent.com/86252234/126378963-ea9f687e-309b-4442-adb1-d7a6c175f71e.png)

**Updated Attribute**

![Screen Shot 2021-07-20 at 11 45 05 AM](https://user-images.githubusercontent.com/86252234/126378976-d0b84e23-7b42-42f2-bf35-724cacda641d.png)

**Incorrect Input**

![Screen Shot 2021-07-20 at 11 45 47 AM](https://user-images.githubusercontent.com/86252234/126378985-c4045cc1-1768-4acd-b827-f9b72d1aa553.png)

**End of Game**

![Screen Shot 2021-07-20 at 11 46 16 AM](https://user-images.githubusercontent.com/86252234/126378990-b034e09c-5761-4aa1-905e-fed76ea267f3.png)


 ## Installation/Usage
 The game is run by the main.cpp executable.
 cmake3. -> make -> ./main -> *user enters input based on what game outputs* -> game end.
 ## Testing
 The Game was stress tested through play testing the game. 
