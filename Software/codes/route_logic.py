# route_logic.py
# Identifies bins above threshold (conceptual route logic)

FILL_THRESHOLD = 80

def get_bins_to_collect(bin_data_list):
    """
    Select bins whose fill level is above threshold
    """
    bins = []

    for data in bin_data_list:
        if data["fill"] >= FILL_THRESHOLD:
            bins.append(data["node_id"])

    return bins
