from controller import Robot, Keyboard

robot = Robot()
timestep = int(robot.getBasicTimeStep())

keyboard = Keyboard()

keyboard.enable(timestep)

motor_names = ['front_left', 'front_right', 'back_left', 'back_right']
motors = []

for name in motor_names:

    motor = robot.getDevice(name)
    motor.setPosition(float('inf'))
    motor.setVelocity(0.0)
    motors.append(motor)

MAX_SPEED = 5.0 

while robot.step(timestep) != -1:
    key = keyboard.getKey()
    
    left_speed = 0.0
    right_speed = 0.0
    
    if key == ord('W') or key == ord('w'):
        left_speed = MAX_SPEED
        right_speed = MAX_SPEED
    elif key == ord('S') or key == ord('s'):
    
        left_speed = -MAX_SPEED
        right_speed = -MAX_SPEED
    elif key == ord('D') or key == ord('a'):
    
        left_speed = -MAX_SPEED
        right_speed = MAX_SPEED
    elif key == ord('A') or key == ord('d'):
        left_speed = MAX_SPEED
        right_speed = -MAX_SPEED
    elif key == ord(' '): 
        left_speed = 0.0
        right_speed = 0.0
        
    motors[0].setVelocity(left_speed)  
    motors[1].setVelocity(right_speed) 
    
    motors[2].setVelocity(left_speed) 
    motors[3].setVelocity(right_speed) 