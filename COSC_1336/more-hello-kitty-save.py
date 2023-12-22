import turtle
w = turtle.Screen()        
w.bgcolor('white')
turtle.screensize(720, 700)

thu = turtle.Turtle()
start_heading = thu.heading()
thu.pensize(5)
def goto(x, y):
    thu.penup()
    thu.goto(x,y)
    thu.pendown()

def drawBow(x,y):
        thu.penup()
        thu.goto(x,y)
        thu.pendown()
        thu.setheading(start_heading)
        thu.color('black', 'hotpink')
        thu.pendown()
        thu.begin_fill()
        thu.circle(15)
        thu.fillcolor('hotpink')
        thu.end_fill()      
        thu.right(45)
        thu.begin_fill()
        #right side of bow
        thu.circle(90, 40)
        thu.left(45)
        thu.circle(90,40)
        thu.left(80)
        thu.circle(90,50)
        thu.right(100)
        thu.circle(15,-80)
        thu.fillcolor('hotpink')
        thu.end_fill()
        thu.penup()
        #left side of bow
        thu.goto(x + -15,y + 10)
        thu.pendown()
        thu.begin_fill()
        thu.left(-45)
        thu.circle(90,-40)
        thu.left(-45)
        thu.circle(90,-40)
        thu.left(-80) 
        thu.circle(90,-50)  
        thu.left(100)
        thu.circle(15,80)
        thu.fillcolor('hotpink')
        thu.end_fill()

def draw_Flower_Bow(x,y):
    goto(x + 15,y + 10)
    thu.setheading(start_heading)
    thu.color('black', 'hotpink')
    thu.pendown()
    thu.begin_fill()
    for i in range(5):
        thu.circle(30, 180)
        thu.right(108)
    thu.end_fill()
    goto(x - 25 ,y + 40)
    thu.dot(40)

# start of hello kitty
def draw_hello_kitty(start_x, start_y, draw_bow_type):
    thu.setheading(start_heading)

    goto(start_x + -110, start_y + 0)
    def flatoval(r):               
        thu.right(45)
        thu.begin_fill()
        for _ in range(2):
            thu.circle(r,90)
            thu.circle(r/2,90)
        thu.end_fill()
    thu.color('black', 'white')
    flatoval(180)

    #left ear
    thu.color('black', 'white')
    thu.penup()
    thu.begin_fill()
    thu.goto(start_x + -50,start_y + 160)
    thu.pendown()
    thu.circle(-100,-30)
    thu.left(70)
    thu.circle(-100,-40)
    thu.penup()
    thu.left(120)
    thu.end_fill()

    #right ear
    thu.color('black', 'white')
    thu.penup()
    thu.begin_fill()
    thu.goto(start_x + 70, start_y + 160)
    thu.pendown()
    thu.left(30)
    thu.circle(90, -30)
    thu.right(70)
    thu.circle(90,-50)
    thu.end_fill()

    #bow
    draw_bow_type(start_x + 100, start_y + 100)

    #nose
    def drawNose(r):
        thu.penup()
        thu.setheading(start_heading)
        thu.goto(start_x + 10, start_y + 18)  
        thu.pendown()  
        thu.color('black','yellow')  
        thu.begin_fill()        
        thu.left(-45)
        for _ in range(2):    
            thu.circle(r,90)   
            thu.circle(r/2,90)
        thu.end_fill()
    drawNose(10.5)

    #eyes
    def drawEyes(x,y): 
        thu.setheading(start_heading) 
        thu.penup()  
        thu.goto(x,y)
        thu.pendown()
        thu.color('black', 'black')  
        thu.begin_fill()         
        thu.left(45)  
        for _ in range(2):      
            thu.circle(12,90)    
            thu.circle(12/2,90)
        thu.end_fill()
    drawEyes(start_x + 80, start_y + 38)  
    drawEyes(start_x + -40, start_y + 38)                 

    #whiskers
    #top right whiskers
    thu.setheading(start_heading)
    thu.penup()
    thu.pensize(4)
    thu.goto(start_x + 140, start_y +50)
    thu.pendown()
    thu.left(30)
    thu.circle(-60,50)
    thu.penup()
    #mid right whiskers
    thu.setheading(start_heading)
    thu.goto(start_x + 150, start_y + 35)
    thu.pendown()
    thu.left(30)
    thu.circle(-40,45)
    thu.penup()
    #bot right whiskers
    thu.setheading(start_heading)
    thu.goto(start_x + 140, start_y + 10)
    thu.left(30)
    thu.pendown()
    thu.circle(-60,50)
    #top left whiskers
    thu.setheading(start_heading)
    thu.penup()
    thu.goto(start_x + -160, start_y + 50)
    thu.pendown()
    thu.left(35)
    thu.circle(-60,50)
    thu.penup()
    #mid left whiskers
    thu.setheading(start_heading)
    thu.penup()
    thu.goto(start_x + -150, start_y + 35)
    thu.pendown()
    thu.left(35)
    thu.circle(-40,45)
    thu.penup()
    #bot left whiskers
    thu.setheading(start_heading)
    thu.penup()
    thu.goto(start_x + -160, start_y + 10)
    thu.pendown()
    thu.left(35)
    thu.circle(-60,50)
    thu.penup()

#stripes
def draw_stripe(x, y, color):
    goto(x,y)
    thu.color(color)
    thu.begin_fill()
    for i in range(2):
        thu.forward(1432)
        thu.right(90)
        thu.forward(50)
        thu.right(90)
    thu.end_fill()

x = -720
y = -450
for i in range(18):
    y = y + 50
    if i % 2:
        draw_stripe(x, y, 'light blue')
    else:
        draw_stripe(x, y, 'pink')

draw_hello_kitty(200, -40, drawBow)
draw_hello_kitty(-200, -40, draw_Flower_Bow)

thu.penup()
thu.color('black')
goto(-250, 200)
thu.pendown()
thu.write('Hello Kitty', font = ('Courier', 85, 'bold' ))

thu.penup()
thu.color('black')
font = ('Courier', 55, 'bold')
goto(-550, -215)
thu.pendown()
thu.write('You can never have too many friends', font = ('Courier', 55, 'bold'))

def star(x, y, size):
    thu.penup()
    goto(x,y)
    thu.color('black')
    angle = 120
    thu.fillcolor('yellow')
    thu.begin_fill()
    for i in range(5):
        thu.forward(size)
        thu.right(angle)
        thu.forward(size)
        thu.right(72 - angle)
    thu.end_fill()
star(-320, 270, 35)
star(420, 270, 35)

thu.hideturtle()
w.exitonclick()
