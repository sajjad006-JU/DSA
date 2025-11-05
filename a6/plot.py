import matplotlib.pyplot as plt
import numpy as np
import math

# ========================
# DATASET 1: RANDOM ARRAY
# ========================
input_sizes = np.array([10000, 50000, 100000, 150000, 200000], dtype=float)

bubble_random = np.array([
    [0.302851, 0.299487, 0.307081, 0.300958, 0.303092],
    [8.013700, 7.948638, 8.187814, 8.153271, 7.934618],
    [31.928963, 32.558166, 32.567070, 32.757516, 32.252995],
    [72.068501, 71.993606, 72.143631, 73.585934, 73.013843],
    [182.804728, 187.287841, 189.775358, 187.930385, 187.191662]
])
selection_random = np.array([
    [0.124428, 0.129768, 0.163505, 0.125900, 0.123872],
    [2.962867, 2.888841, 2.965706, 2.968377, 2.829480],
    [11.316596, 11.292371, 11.414013, 11.282444, 11.446243],
    [25.365642, 25.342968, 25.408509, 25.343411, 25.386094],
    [45.043949, 45.178386, 45.262482, 45.445389, 45.478030]
])
insertion_random = np.array([
    [0.084570, 0.084910, 0.084011, 0.085485, 0.085758],
    [1.942414, 1.952990, 1.945075, 1.941795, 1.937388],
    [7.876914, 7.779602, 7.770216, 7.801247, 7.812390],
    [17.427680, 17.428690, 17.344614, 17.342372, 17.554993],
    [31.124143, 30.687581, 30.863921, 30.686393, 31.207726]
])
quick_random = np.array([
    [0.003130, 0.003219, 0.003215, 0.003144, 0.003074],
    [0.012078, 0.014338, 0.010889, 0.012849, 0.012421],
    [0.024244, 0.020505, 0.021604, 0.022457, 0.020864],
    [0.029375, 0.030880, 0.031132, 0.032108, 0.031117],
    [0.039876, 0.040044, 0.042476, 0.041068, 0.041304]
])

bubble_avg_random = np.mean(bubble_random, axis=1)
selection_avg_random = np.mean(selection_random, axis=1)
insertion_avg_random = np.mean(insertion_random, axis=1)
quick_avg_random = np.mean(quick_random, axis=1)

print("random", bubble_avg_random, selection_avg_random, insertion_avg_random, quick_avg_random)

# ========================
# DATASET 2: SORTED ARRAY
# ========================
bubble_sorted = [
    [0.130427, 0.130774, 0.135805, 0.131932],
    [3.168508, 3.056301, 3.155589, 3.147371, 3.158004],
    [12.352371, 12.373706],
    [27.491464],
    [49.849912]
]
selection_sorted = [
    [0.124455, 0.122845, 0.125473, 0.124033],
    [2.975617, 3.031092, 2.922896, 2.898770, 2.916772],
    [11.730053, 11.690191],
    [26.489548],
    [46.703147]
]
insertion_sorted = [
    [0.000096, 0.000096, 0.000073, 0.000097],
    [0.000481, 0.000473, 0.000473, 0.000287, 0.000270],
    [0.000942, 0.000952, 0.000944, 0.000944, 0.000951],
    [0.001354, 0.001554, 0.001659, 0.001827, 0.001421],
    [0.002110, 0.002095, 0.002225, 0.002139, 0.002042]
]
quick_sorted = [
    [0.417695, 0.415124, 0.417010, 0.419020],
    [10.187927, 10.200414, 10.153799, 10.240951, 10.143057],
    [40.727710],
    [91.047794],
    [math.nan]
]

bubble_avg_sorted = [np.mean(b) for b in bubble_sorted]
selection_avg_sorted = [np.mean(s) for s in selection_sorted]
insertion_avg_sorted = [np.mean(i) for i in insertion_sorted]
quick_avg_sorted = [np.nanmean(q) for q in quick_sorted]

print("sorted", bubble_avg_sorted, selection_avg_sorted, insertion_avg_sorted, quick_avg_sorted)

# =============================
# DATASET 3: REVERSE SORTED
# =============================
bubble_reverse = [
    [0.170430, 0.175262, 0.169854, 0.172372, 0.166918],
    [4.276540, 4.194674, 4.171159, 4.227250, 4.305116],
    [18.830857, 19.095577, 19.023402, 18.916298, 19.155364],
    [42.860130, 41.119228],
    [81.673394, 83.715207]
]
selection_reverse = [
    [0.178864, 0.175206, 0.176237, 0.175156, 0.173492],
    [2.549870, 2.437653, 2.450478, 2.439953, 2.442880],
    [10.795319, 10.427080, 10.511272, 10.715563, 10.671273],
    [23.701219, 23.370389],
    [50.003215, 52.033262]
]
insertion_reverse = [
    [0.170989, 0.173429, 0.175738, 0.195244, 0.172092],
    [2.985159, 2.781859, 2.757218, 2.847010, 2.835219],
    [12.486461, 12.459324, 12.204033, 11.834567, 11.934601],
    [28.242880, 29.870249],
    [60.837819, 62.627431]
]
quick_reverse = [
    [0.174743, 0.165764, 0.169574, 0.174100, 0.173377],
    [3.647546, 3.737251, 3.650118, 3.759842, 3.899810],
    [15.426031, 13.917806, 14.137150, 14.584409, 14.488171],
    [36.103569, 35.307201],
    [math.nan]
]

bubble_avg_reverse = [np.mean(b) for b in bubble_reverse]
selection_avg_reverse = [np.mean(s) for s in selection_reverse]
insertion_avg_reverse = [np.mean(i) for i in insertion_reverse]
quick_avg_reverse = [np.nanmean(q) for q in quick_reverse]

print("reverse", bubble_avg_reverse, selection_avg_reverse, insertion_avg_reverse, quick_avg_reverse)

# =============================
# PLOTTING: ALL THREE SUBPLOTS
# =============================
fig, axes = plt.subplots(1, 3, figsize=(18, 5), sharey=True)

# Data for each subplot
datasets = [
    (bubble_avg_random, selection_avg_random, insertion_avg_random, quick_avg_random, "Random Array"),
    (bubble_avg_sorted, selection_avg_sorted, insertion_avg_sorted, quick_avg_sorted, "Sorted Array"),
    (bubble_avg_reverse, selection_avg_reverse, insertion_avg_reverse, quick_avg_reverse, "Reverse Sorted Array")
]

for ax, (b, s, i, q, title) in zip(axes, datasets):
    ax.plot(input_sizes, b, 'o-', label='Bubble Sort')
    ax.plot(input_sizes, s, 's-', label='Selection Sort')
    ax.plot(input_sizes, i, '^-', label='Insertion Sort')
    ax.plot(input_sizes, q, 'd-', label='Quick Sort')
    ax.set_title(title)
    ax.set_xlabel("Input Size (n)")
    ax.grid(True, linestyle='--', alpha=0.6)

axes[0].set_ylabel("Average Time (seconds)")
axes[0].legend(loc="upper left")
plt.suptitle("Execution Time Comparison for Sorting Algorithms", fontsize=16)
plt.tight_layout(rect=[0, 0, 1, 0.95])
plt.show()
