*This project has been created as part of the 42 curriculum by tireis, eboulla.*

# Push_swap 

## Description
`push_swap` is a highly optimized algorithmic project at 42 where the goal is to sort data on a stack (`a`) using a limited set of instructions and a secondary stack (`b`). The objective is to calculate and display the smallest possible sequence of Push_swap language operations on the standard output to sort a given list of unique integers in ascending order.

Our implementation features a fully dynamic **Adaptive Strategy Selector**. Before performing any moves, the program calculates the structural disorder of the data and automatically invokes the most mathematically efficient sorting configuration at runtime.

---

## Group Contribution & Roles
This project was completed as a 2-learner group activity. Both learners contributed meaningfully and fully understand the entire codebase. The division of work is as follows:

* **`tireis`**:
    * Structured the underlying double-linked list data structures and error-checking/parsing mechanics.
    * Implemented the mandatory mathematical `disorder_metric`.
    * **Simple Algorithm (`MODE_SIMPLE`)**: Designed and wrote the specialized sorting logic for minimal sets ($N \le 5$).
    * **Medium Algorithm (`MODE_MEDIUM`)**: Conceived and implemented the square-root-based chunking method.
    * Developed the live telemetry and operational tracking module (`t_bench`).
* **`eboulla`**:
    * **Complex Algorithm (`MODE_COMPLEX`)**: Researched and implemented the bitwise Radix Sort adaptation for large-scale data ($N \ge 500$).
    * Developed and optimized the global input pre-indexing matrix (`index.c`).
    * Collaborated on extensive benchmarking, testing, and calibrating the custom adaptive thresholds.

---

## Technical Choices & Algorithm Rationale

### 1. Pre-Indexing Matrix (`index.c`)
To ensure our algorithms remain unimpacted by the magnitude of input values (e.g., handles extreme values like `INT_MAX`, `INT_MIN`, or distant negative boundaries), we implemented a pre-indexing step. Arguments are parsed, validated, cloned into a temporarily allocated heap array, and sorted. The original stack values are then systematically mapped to their relative index positions (`0` to `N - 1`). For instance, a chaotic pool like `[100, -45, 2000]` gracefully transforms into `[1, 0, 2]`. This dramatically optimizes bit-masking in Radix and chunk calculations.

### 2. The Four Sorting Strategies

#### Simple Algorithm ($O(n^2)$) — `MODE_SIMPLE`
* **Internal Technique**: A highly specialized `sort_three` handler engineered to sort three integers in a maximum of 2 moves. For 4 or 5 elements, it evaluates the stack to locate the lowest indexes, pushes them to stack `b` via `pb` until exactly 3 nodes remain in `a`, triggers the 3-element sort, and then pulls them back via `pa`.
* **Complexity Upper Bound**: Time: $O(n^2)$, Space: $O(n)$. Since $n \le 5$, the instruction footprint stays well below project ceilings.

#### Medium Algorithm ($O(n\sqrt{n})$) — `MODE_MEDIUM`
* **Internal Technique**: **Square-Root Chunk-Based Sorting**. The module dynamically calculates the optimal chunk distribution using the square root of the dataset size ($\sqrt{N}$). For 100 elements, it selects a window size of 10. It strategically pushes specified index ranges (e.g., elements falling within $0-9$, then $10-19$) into stack `b`. When returning elements to stack `a`, it tracks the highest index and uses the shortest rotation route (`ra` or `rra`) to surface it to the top before pushing.
* **Complexity Upper Bound**: Time: $O(n\sqrt{n})$, Space: $O(n)$. This crushes the required operation limits for 100 random elements.

#### Complex Algorithm ($O(n \log n)$) — `MODE_COMPLEX`
* **Internal Technique**: **Bitwise Least Significant Digit (LSD) Radix Sort**. Leveraging our continuous sequence of relative indices (`0` to `N-1`), this algorithm evaluates elements bit by bit using a dynamic bit-shift loop calculated by `get_max_bits`. If the evaluated bit is `0`, the element is isolated to stack `b` (`pb`); if it's `1`, it rotates down stack `a` (`ra`). One full sweep is done per bit column, resulting in a completely sorted sequence.
* **Complexity Upper Bound**: Time: $O(n \cdot \text{Total Bits}) \approx O(n \log n)$, Space: $O(n)$. It ensures complete mathematical predictability and handles 500+ items seamlessly.

#### Adaptive Algorithm — `MODE_ADAPTIVE`
* **Threshold Rationale**: The subject mandates a disorder value between 0 and 1, analyzing pair inversions (mistakes over total possible pairs). Our adaptive controller dynamically reads this metric before making a single shift and assigns the target configuration according to these strict parameters:
    * **Disorder $< 0.2$ (Low Disorder)**: Routes directly to `MODE_SIMPLE` or `MODE_MEDIUM`. In almost-sorted stacks, a Radix sort wastes cycles inspecting bit columns for values already in order. Local shift adjustments are far more cost-effective.
    * **$0.2 \le$ Disorder $< 0.5$ (Medium Disorder)**: Forces `MODE_MEDIUM`. Chunking proves highly responsive here, grouping local index numbers efficiently with minimal traveling distance.
    * **Disorder $\ge 0.5$ (High Disorder)**: Triggers `MODE_COMPLEX`. High entropy requires a structural algorithm that completely ignores positional bias and sorts data based entirely on binary value columns.

---

## Instructions

### Compilation
The provided `Makefile` compiles the required sources along with our internal `ft_printf` module while preventing any forbidden relinking behavior:
```bash
make
