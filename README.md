# Dolphin ICPC Notebook Generator

A powerful, LaTeX-based notebook generator designed for competitive programming contests like ICPC, leveraging the KACTL template style. The project streamlines the process of organizing algorithms, code snippets, and utilities into a well-structured PDF.

---

## Prerequisites

Ensure you have the following tools installed on your system before proceeding:

- **LaTeX**: Ensure the following packages are included: `listings`, `multicol`, `fancyhdr`, and others.
- **Python 3**: Required for scripting and automation.
- **Make**: A build tool to simplify the compilation process.
- **C++ Compiler**: For testing and validating code snippets.

---

## Quick Start

### Using Docker (Recommended)

1. **Build the Docker image:**
   ```bash
   docker build -t dolphin-icpc-notebook .
   ```

2. **Run the container:**
   ```bash
   docker run --rm -v $(pwd):/workspace dolphin-icpc-notebook make kactl
   ```

### Without Docker

1. **Install prerequisites** as mentioned above.
2. Clone this repository:
   ```bash
   git clone https://github.com/your-repo/dolphin-icpc-notebook.git
   cd dolphin-icpc-notebook
   ```
3. Build the notebook:
   ```bash
   make kactl
   ```

---

## Project Structure

The project follows a modular structure:

- **`content/`**: Source code organized by topics
  - **`contest/`**: Templates and debugging tools.
  - **`data-structures/`**: Implementations of key data structures.
  - **`dynamic-programming/`**: Algorithms for DP problems.
  - **`graph/`**: Graph-related algorithms.
  - **`math/`**: Mathematical functions and algorithms.
  - **`strings/`**: String manipulation algorithms.

- **`doc/`**: Documentation and supporting scripts.
- **`stress-tests/`**: Framework for testing algorithms.
- **`build/`**: Directory for generated files (created during the build process).

---

## Available Commands

Use the `make` command with the following targets:

- **`make fast`**: Perform a quick build (single LaTeX pass).
- **`make kactl`**: Complete build with multiple passes for optimal formatting.
- **`make clean`**: Remove intermediate build files.
- **`make veryclean`**: Remove all generated files and outputs.
- **`make test`**: Execute all stress tests.
- **`make test-compiles`**: Ensure all headers compile successfully.

---

## Customization

### 1. Modify Team Information

Edit the `content/kactl.tex` file to include your team’s name, logo, and other details. For example, replace the placeholder logo with your university’s:

```latex
\includegraphics[width=5cm]{content/tex/fpt.png}
```

### 2. Add New Algorithms

To integrate new algorithms:

1. Create a `.h` file under the appropriate subdirectory in `content/`.
2. Add the corresponding import line to the relevant `chapter.tex` file. For example:
   ```latex
   \kactlimport{new-algorithm.h}
   ```

### 3. Update Styles

Customize the LaTeX styling in the `kactl.cls` file to match your preferences.

---

## Testing

### Run Stress Tests

To validate the correctness of algorithms, use the stress testing framework:

```bash
make test
```

### Test Individual Snippets

Compile and run individual files within the `stress-tests/` directory.

---

## Output

The final notebook will be generated as `kactl.pdf` in the root directory. Open it with any PDF viewer to verify the content and formatting.

---

## Contributing

We welcome contributions! Please follow these guidelines:

1. Maintain the existing coding style.
2. Include proper documentation for all new algorithms.
3. Add relevant stress tests for new additions.
4. Ensure all tests pass before submitting a pull request.

---

## Troubleshooting

If you encounter issues during the build process:

1. Verify that LaTeX is installed with all required packages.
2. Ensure Python 3 is properly configured on your system.
3. Check for any compilation errors in the terminal output.
4. Confirm that the `build/` directory has the necessary file permissions.

---

## License

This project is based on the KACTL template and is released under the same license. Refer to individual source files for specific licensing information.

---

With **Dolphin ICPC Notebook Generator**, organizing your algorithms has never been easier. Good luck, and may your contests be bug-free!

