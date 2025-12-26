# data_store.py
# Stores received bin data in a simple list (for demo)

bin_data_list = []

def store_data(data):
    """
    Store parsed bin data
    """
    bin_data_list.append(data)

def show_all_data():
    """
    Display all received bin data
    """
    for data in bin_data_list:
        print(data)
