import json

class JSonExporter(object):
    def __init__(self, filename):
        super(JSonExporter, self).__init__()
        self.filename = filename
        self.freeCells = []
        self.enemiesCells = []
        self.playerCell = None
        self.exitCell = None
        
        
    def unique(self, alist):
        """Removes duplicates from a list."""
        no_dupes = []
        [no_dupes.append(i) for i in alist if not no_dupes.count(i)]
        return no_dupes
        
        
    def add_free_cell(self, cell_tuple):
        self.freeCells.append(cell_tuple)
        
    def add_enemy_cell(self, enemy_cell):
        self.enemiesCells.append(enemy_cell)
        
    def remove_free_cell(self, cell_tuple):
        try:
            self.freeCells.remove(cell_tuple)
        except(ValueError):
            pass
        
    def remove_enemy_cell(self, cell_tuple):
        try:
            self.enemiesCells.remove(enemy_cell)
        except(ValueError):
            pass
        
    def add_player_cell(self, cell_tuple):
        self.playerCell = cell_tuple
        
    def add_exit_cell(self, cell_tuple):
        self.exitCell = cell_tuple

        
        
    def export(self):
        #Put everything into a dictionary
        json_dict = dict()
        json_dict["map"] = dict()
        json_dict["map"]["free"] = self.unique(self.freeCells)
        json_dict["map"]["enemies"] = self.unique(self.enemiesCells)
        json_dict["map"]["player"] = self.playerCell
        json_dict["map"]["exit"] = self.exitCell
        
        json_as_string = json.dumps(json_dict, indent = 4)
        
        #Save the string on a file, overwriting the content if necessary
        file = open(self.filename, 'w')
        file.write(json_as_string)
        file.close()
    
        