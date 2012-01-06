import pygame
import sys
from pygame.locals import *
from pgu import gui
from jsonexporter import JSonExporter
from brushes import *
from cells import *


def get_cell_id(x, y, cell_size = 20, cell_offset = 2):
    """
    Get the proper cell id. Need to generate a correct JSON level file.
    TODO: OutOfBoundary Detection. 
    """
    return (x/cell_size + 1), (y/cell_size + 1)

 
def main():
    
    #Library initialization
    pygame.init()
    pygame.display.set_caption('SIGSEGV MAP EDITOR')
    
    #Some const variables
    resolution = (800,600)
    screen = pygame.display.set_mode(resolution)
    screen.fill((0,0,30))
 
    line_color = (0,100,200)
    red_color = (255,0,0)
    blue_color = (0,0,255)
    
    
    #Creation of exporter and brushes
    exporter = JSonExporter("UntitledLevel.json")
    
    #Create the group that will contains the cells
    cells = pygame.sprite.RenderPlain()
    
    #Free cell brush, red
    box = pygame.Rect(0, 0, CELL_SIDE - CELL_BORDER, CELL_SIDE - CELL_BORDER)
    free_cell_brush = FreeCellBrush(cells, exporter)
    
    #Enemy cell brush, blue
    enemy_cell_brush = EnemyCellBrush(cells, exporter)
    
    #Player cell brush, yellow
    player_cell_brush = PlayerCellBrush(cells, exporter)
    
    #Exit cell brush, green
    exit_cell_brush = ExitCellBrush(cells, exporter)
    
    
    
    def label(text, size, x, y, color = (255,255,255)):
        font = pygame.font.Font(pygame.font.match_font('menlo'), size)
        text = font.render(text, 1, color)
        screen.blit(text, (x,y))
    
    
    
    
    #Draw tools
    label("SIGSEGV MAP EDITOR", 25, 300, 10)
    label("Left mouse click: Draw a cell.", 20, 10, 25)
    label("Right mouse click: Delete a cell.", 20, 10, 45)
    label("Press F to switch to the free cell brush", 20, 10, 65, color = red_color)
    label("Press E to switch to the enemy cell brush", 20, 300, 65, color = (0,80,255))
    label("Press P to switch to the player start brush", 20, 10, 85, color = (255,255,0))
    label("Press X to switch to the exit cell brush", 20, 300, 85, color = (0,255,0))
    label("Press S to export the current map to a file.", 20, 250, 500, color = red_color)
    
    #Draw vertical lines
    vertical_cycles = resolution[0] / CELL_SIDE
    for x in range(6, vertical_cycles - 5):
        offset = x * CELL_SIDE
        pygame.draw.line(screen, line_color, 
                         (offset,6*CELL_SIDE), 
                         (offset, resolution[1] - 6*CELL_SIDE), 
                         CELL_BORDER)
        
        
    #Draw horizontal lines
    horizontal_cycles = resolution[1] / CELL_SIDE
    for x in range(6, horizontal_cycles - 5):
        offset = x * CELL_SIDE
        pygame.draw.line(screen, line_color, 
                         (6*CELL_SIDE, offset),
                         (resolution[0] - 6*CELL_SIDE, offset),
                         CELL_BORDER)
        
 
    #Update the display
    pygame.display.flip()
    
    #Set the current brush to free cells
    current_brush = free_cell_brush
    
    #Editor logic: whenever the user click into a grid with a selected 
    #"brush", the grid cell will be colored with the selected brush color.
    while 1:
        for e in pygame.event.get():
 
            if e.type == QUIT or (e.type == KEYUP and e.key == K_ESCAPE):
                sys.exit(0)
            
            # if 'F' is pressed, switch to free cell brush
            if e.type == KEYDOWN and e.key == 102:
                current_brush = free_cell_brush
                
            # if 'E' is pressed, switch to enemy cell brush
            if e.type == KEYDOWN and e.key == 101:
                current_brush = enemy_cell_brush
                
            # if 'P' is pressed, switch to player cell brush
            if e.type == KEYDOWN and e.key == 112:
                current_brush = player_cell_brush  
                
            # if 'X' is pressed, switch to exit cell brush
            if e.type == KEYDOWN and e.key == 120:
                current_brush = exit_cell_brush
                
                
                    
            if e.type == MOUSEBUTTONDOWN:
                
                cell_id = get_cell_id(e.pos[0], e.pos[1])
                
                #Left mouse, draws free cells
                if e.button == 1:     
                    current_brush.draw(cell_id)
                    
                #Right mouse, delete cells
                if e.button == 3:
                    current_brush.delete(cell_id)
                    
            #Catch whether the user press S to save the map.
            if e.type == KEYDOWN and e.key == 115:
                print "Saving file on disk."
                exporter.export()
                print "File saved."
 
 
            cells.update()
            cells.draw(screen)
            pygame.display.flip()
            
            
 
 
if __name__ == "__main__":
   main()
