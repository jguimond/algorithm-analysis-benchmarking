import numpy as np
import matplotlib.pyplot as plt

# Generate data for linear search O(n)
n = np.arange(1, 51)  # From 1 to 50
linear_search = n  # Linear search grows linearly

# Generate data for binary search O(log n)
binary_search = np.log2(n)  # Binary search grows logarithmically

# Create the plot
plt.figure(figsize=(8, 6))

# Plot Linear Search
plt.plot(n, linear_search, label="Linear Search", color='orange', linewidth=3)
plt.text(40, 45, 'O(n)', fontsize=12, color='orange')  # Label for O(n), spaced away from the line

# Plot Binary Search
plt.plot(n, binary_search, label="Binary Search", color='blue', linewidth=3)
plt.text(40, np.log2(40) + 2, 'O(log n)', fontsize=12, color='blue')  # Label for O(log n), spaced away from the line

# Add axis labels and title
plt.xlabel("Input Size (n)", fontsize=12)
plt.ylabel("Operations", fontsize=12)
plt.title("Linear Search vs Binary Search", fontsize=14)

# Add legend
plt.legend()

# Add grid for better readability
plt.grid(True)

# Set limits for the axes
plt.xlim(0, 50)
plt.ylim(0, 50)

# Show the plot
plt.show()
