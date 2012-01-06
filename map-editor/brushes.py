import pygame
from cells import *

class Brush(object):
    """Indeed can draw only rects."""
    def __init__(self, group, color):
        super(Brush, self).__init__()
        self._group = group
        self._color = color
        
    def shape():
        doc = "The shape property."
        def fget(self):
            return self._shape
        def fset(self, value):
            self._shape = value
        return locals()
    shape = property(**shape())
    
    def color():
        doc = "The color property."
        def fget(self):
            return self._color
        def fset(self, value):
            self._color  = value
        return locals()
    color = property(**color())
        
    
    def draw(self, cell_id):
        #Create a new cell
        x = (cell_id[0]-1) * CELL_SIDE + CELL_BORDER
        y = (cell_id[1]-1) * CELL_SIDE + CELL_BORDER
        
        cell = Cell((x,y), self._color)
        cell.add(self._group)
        
        
    def delete(self, cell_id):
        cell_list = self._group.sprites()
        
        # Get cell true coords
        x = (cell_id[0]-1) * CELL_SIDE + CELL_BORDER
        y = (cell_id[1]-1) * CELL_SIDE + CELL_BORDER
        
        for c in cell_list:
            if c.position[0] == x and c.position[1] == y:
                c.kill()
                self._group.remove(c)
        
        
        
class FreeCellBrush(Brush):
    """docstring for FreeCellBrush"""
    def __init__(self, group, exporter):
        super(FreeCellBrush, self).__init__(group, (255,0,0))
        self._exporter = exporter
        
        
    def draw(self, cell_id):
        super(FreeCellBrush, self).draw(cell_id)
        self._exporter.add_free_cell(cell_id)
    
        
    def delete(self, cell_id):
        super(FreeCellBrush, self).delete(cell_id)
        self._exporter.remove_free_cell(cell_id)
        
        
class EnemyCellBrush(Brush):
    """docstring for EnemyCellBrush"""
    def __init__(self, group, exporter):
        super(EnemyCellBrush, self).__init__(group, (0,0,255))
        self._exporter = exporter
        
        
    def draw(self, cell_id):
        super(EnemyCellBrush, self).draw(cell_id)
        self._exporter.add_enemy_cell(cell_id)
        
        
    def delete(self, cell_id):
        super(EnemyCellBrush, self).delete(cell_id)
        self._exporter.remove_enemy_cell(cell_id)
    
        
        
class PlayerCellBrush(Brush):
    """docstring for PlayerCellBrush"""
    def __init__(self, group, exporter):
        super(PlayerCellBrush, self).__init__(group, (255,255,0))
        self._exporter = exporter
        
        
    def draw(self, cell_id):
        super(PlayerCellBrush, self).draw(cell_id)
        self._exporter.add_player_cell(cell_id)
        
        
    def delete(self, cell_id):
        super(PlayerCellBrush, self).delete(cell_id)
        self._exporter.add_player_cell(cell_id) #Overwrite previous
        
        
class ExitCellBrush(Brush):
    """docstring for ExitCellBrush"""
    def __init__(self, group, exporter):
        super(ExitCellBrush, self).__init__(group, (0,255,0))
        self._exporter = exporter
        
        
    def draw(self, cell_id):
        super(ExitCellBrush, self).draw(cell_id)
        self._exporter.add_exit_cell(cell_id)
        
        
    def delete(self, cell_id):
        super(ExitCellBrush, self).delete(cell_id)
        self._exporter.add_exit_cell(cell_id) #Overwrite previous
    
