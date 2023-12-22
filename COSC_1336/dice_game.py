import random
dices = [
            [
                '-----------', 
                '|         |', 
                '|         |', 
                '|         |', 
                '-----------'
            ],
            [
                '-----------', 
                '|         |', 
                '|    o    |', 
                '|         |', 
                '-----------'
            ],
            [
                '-----------', 
                '|    o    |', 
                '|         |', 
                '|    o    |', 
                '-----------'
            ],
            [
                '-----------', 
                '|    o    |', 
                '|    o    |', 
                '|    o    |', 
                '-----------'
            ],
            [
                '-----------', 
                '|  o   o  |', 
                '|         |', 
                '|  o   o  |', 
                '-----------'
            ],
            [
                '-----------', 
                '|  o   o  |', 
                '|    o    |', 
                '|  o   o  |', 
                '-----------'
            ],
            [
                '-----------', 
                '|  o   o  |', 
                '|  o   o  |', 
                '|  o   o  |', 
                '-----------'
            ],
        ]

def get_dice(num):
    return dices[num]

def combine_dices(left, right):
    result = []
    for i in range(len(left)):
        result.append(left[i] + ' ' + right[i])
    return result

def draw_dice(dice):
    for row in dice:
        print(row)

def get_result_from_dice_rolls(dice_rolls):
    dice1 = get_dice(dice_rolls[0])
    dice2 = get_dice(dice_rolls[1])
    dice3 = get_dice(dice_rolls[2])
    return combine_dices(combine_dices(dice1, dice2), dice3)

print('Welcome to the Roll 3 Dice Game!!!')

question = ''
runs = 0 
wins = 0
losses = 0

while question == '' or question == 'Y' or question == 'y':
    question = str(input('Roll the Dice? (Y/N) '))
    if question == 'N' or question == 'n':
        print ("See ya!!!") 
    elif question == 'Y' or question == 'y':
        print("Let's roll your dice!!!")
        you_dice_roll = random.randint(1, 6),  random.randint(1, 6), random.randint(1, 6)
        new_you = int(you_dice_roll[0])
        new1_you = int(you_dice_roll[1])
        new2_you = int(you_dice_roll[2])
        you_added = sum(you_dice_roll)
        combo_dice = get_result_from_dice_rolls(you_dice_roll)
        draw_dice(combo_dice)
        print()

        print("It's AI's turn to roll the dice!!!")
        ai_dice_roll =  random.randint(1, 6), random.randint(1, 6), random.randint(1, 6) 
        new_ai = int(ai_dice_roll[0])
        new1_ai = int(ai_dice_roll[1])
        new2_ai = int(ai_dice_roll[2])
        ai_added = sum(ai_dice_roll)
        combo_dice = get_result_from_dice_rolls(ai_dice_roll)
        draw_dice(combo_dice)
        print(f'YOU ({you_added}) {new_you},{new1_you},{new2_you} - {new_ai},{new1_ai},{new2_ai} ({ai_added}) AI')
        print()
        if you_added == ai_added:
            print('Draw?!!')
        elif you_added > ai_added:
            print('You win!!!')
            wins += 1
        else:
            print('AI wins...')
            losses += 1

        runs += 1
        print(f'GRAND TOTAL AFTER THE RUN #{runs}: YOU {wins} - {losses} AI (Win Ratio: {(wins / runs):.3f})')


        
    



   



