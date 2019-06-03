# Baccarat
Baccarat game without graphical interface. Exersice to in order to practice the basic c knowledge when I was student in TUC. The program is simulating the Bacarrat game and user is playing against the PC. 

In order to run the code in Linux environment after you clone that project: 

### Step 1
    Build/Create an executable : gcc -o bacarrat Baccarat.c .

### Step 2
    Run the executable using: ./bacarrat . 

Then you will be asked to provide the starting money. The ammount should be of range (0-500). Then you will draw the first card and the sum of your cards will appear looking like that:
    -- Your sum is:2
    -- 2 + 0

Then you will be asked to bet. After your bet the new card will be drawn and also PC will draw a card. The biggest sum of cards will win and if you win you will get your bet twice back. In bacarrat the biggest possible sum is 9. 

You can find more information about the game here: https://en.wikipedia.org/wiki/Baccarat_(card_game). 

After that you will be asked if you want to see the rest of the cards and if not you will be asked if you want to leave the game.
