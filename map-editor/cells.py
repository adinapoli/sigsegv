import pygame


CELL_SIDE = 20
CELL_BORDER = 2


class Cell(pygame.sprite.Sprite):
    """I need to subclass Sprite cause i need to
       remove cell from screen."""
       
    def __init__(self, position, color):
        super(Cell, self).__init__()
        self._position = position
        self._color = color
        
        # create an image
        surface = pygame.Surface((CELL_SIDE - CELL_BORDER, CELL_SIDE - CELL_BORDER))
        surface.fill(color)
        pygame.draw.rect(surface, color, pygame.Rect(position[0], position[1], CELL_SIDE-CELL_BORDER, CELL_SIDE-CELL_BORDER))
 
        # set image and rect so we can be rendered
        self.image = surface
        self.rect = surface.get_rect()
        self.rect.move_ip(position)
        
        
    def position():
        doc = "The position property."
        def fget(self):
            return self._position
        def fset(self, value):
            self._position = value
        def fdel(self):
            del self._position
        return locals()
    position = property(**position())
        