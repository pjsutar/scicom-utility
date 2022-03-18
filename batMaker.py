import os

def batMaker():
    '''
    Utility script to make .bat files
    Search for Test Reports folder
    Read names of subdirs i.e. units
    Walk down path to Test Plan folder
    Create .bat file to copy test results for each unit to SharePoint
    '''

# Setup
    parent_path = "V:\Refrigeration Test Lab"
    target = "Test Reports"
    bat_folder = "Test Plan"

# Search for 'Test Reports' folder
    subfolders = os.listdir(parent_path)

    for subfolder in subfolders:
        sub_path = os.path.join(parent_path, subfolder)
        
        if os.path.isfile(sub_path):
            pass

        # When 'Test Reports' folder is found...
        elif os.path.isdir(sub_path) and target in os.path.isdir(sub_path):
            reports_path = sub_path
            units = os.listdir(sub_path)
            
            # Walk down path to get 'Test Plan' folder
            cur_dir = os.getcwd(sub_path)
            while os.path.basename(cur_dir):
                cur_dir = os.path.dirname(cur_dir)
                if bat_folder in cur_dir:
                    break
                else:
                    continue

            # Write .bat file for each unit
            for unit in units:
                unit_path = os.path.join(reports_path, unit)
                with open(f'{cur_dir}/{unit}.bat', 'w') as bat_file:
                    bat_file.write(f"Copy from V:/{unit_path} to J:/{unit}")
                bat_file.close()

        else:
            pass


if __name__ == "__main__":
    batMaker()