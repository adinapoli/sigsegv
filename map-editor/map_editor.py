import pygame
import sys
from pygame.locals import *



def get_cell_id(x, y, cell_size = 20, cell_offset = 2):
    """
    Get the proper cell id. Need to generate a correct JSON level file.
    TODO: OutOfBoundary Detection. 
    """
    return (x/cell_size + 1), (y/cell_size + 1)

 
def main():
    pygame.init()
    
    
    resolution = (800,600)
    screen = pygame.display.set_mode(resolution)
    screen.fill((0,0,30))

    CELL_SIDE = 20
    CELL_BORDER = 2
 
    line_color = (0,100,200)
    red_color = (255,0,0)
    blue_color = (0,0,255)
    
    #Draw vertical lines
    vertical_cycles = resolution[0] / CELL_SIDE
    for x in range(6, vertical_cycles - 5):
        offset = x * CELL_SIDE
        pygame.draw.line(screen, line_color, (offset,6*CELL_SIDE), (offset, resolution[1] - 6*CELL_SIDE), CELL_BORDER)
        
        
    #Draw horizontal lines
    horizontal_cycles = resolution[1] / CELL_SIDE
    for x in range(6, horizontal_cycles - 5):
        offset = x * CELL_SIDE
        pygame.draw.line(screen, line_color, (6*CELL_SIDE, offset), (resolution[0] - 6*CELL_SIDE, offset), CELL_BORDER)
        
 
    #Update the display
    pygame.display.flip()
    
    
    #Editor logic: whenever the user click into a grid with a selected "brush",
    #The grid cell will be colored with the selected brush color.
    while 1:
        for e in pygame.event.get():
 
            if e.type == QUIT or (e.type == KEYUP and e.key == K_ESCAPE):
                sys.exit(0)
            if e.type == MOUSEBUTTONDOWN:
                
                #Left mouse, draws free cells
                if e.button == 1:
                    cell_id = get_cell_id(e.pos[0], e.pos[1])
                    box_x = (cell_id[0]-1) * CELL_SIDE + CELL_BORDER
                    box_y = (cell_id[1]-1) * CELL_SIDE + CELL_BORDER
                    red_box = pygame.Rect(box_x, box_y, CELL_SIDE - CELL_BORDER, CELL_SIDE - CELL_BORDER)
                    pygame.draw.rect(screen, red_color, red_box)
                    
                #Right mouse, draws enemies
                if e.button == 3:
                    cell_id = get_cell_id(e.pos[0], e.pos[1])
                    box_x = (cell_id[0]-1) * CELL_SIDE + CELL_BORDER
                    box_y = (cell_id[1]-1) * CELL_SIDE + CELL_BORDER
                    blue_box = pygame.Rect(box_x, box_y, CELL_SIDE - CELL_BORDER, CELL_SIDE - CELL_BORDER)
                    pygame.draw.rect(screen, blue_color, blue_box)
 
 
            pygame.display.flip()
                 #if e.button == 1:
                 #    print "left button clicked"
                 #elif e.button == 2:
                 #    print "middle button clicked"
                 #elif e.button == 3:
                 #    print "right button clicked"
                 #elif e.button == 4:
                 #     print "scrolling forward"
                 #elif e.button == 5:
                    # print "scrolling backward"
                 #else:
                 #    print "some cool button"
 
 
if __name__ == "__main__":
   main()
