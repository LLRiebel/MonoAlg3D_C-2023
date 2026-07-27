This version of MonoAlg3D contains custom functions to reproduce the results in Riebel et al., Scientific Reports (2024), https://doi.org/10.1038/s41598-024-67951-5 and Riebel et al., Stem Cell Reports (2026), https://doi.org/10.1016/j.stemcr.2026.103007.

Accompanying Purkinje and biventricular infarction mesh files can be found in https://doi.org/10.5281/zenodo.14699735.

Example configuration files are provided in custom_configs/.

NOTE: 
- If you WANT TO USE the STEM CELL functionality, please edit lines 806 and following of the src/models_library/ToROrd/Paci_ToRORd_dynCl_PhiCaL_IKCa_mixed_apicobasal_infarctionRemod_RL.common.c file. To test the stem cell model, a test case initilisation file and single-cube-mesh are available in this repository in custom_configs/ and meshes/.
- If you DO NOT WANT TO USE the STEM CELL functionality, please note that some changes may be required in the code (it should work but hasn't been thoroughly tested without stem cells). You may want to remove mention of stem cells or Paci in the src/models_library/ToROrd/Paci_ToRORd..., src/domains_library/custom_functions.c, src/domains_library/custom_mesh_info_data.h, src/extra_data_library/custom_functions.c, src/matrix_assembly_library/custom_functions.c, and src/matrix_assembly_library/purkinje_coupling_matrix_assembly.c files.


# MonoAlg3D ![build](https://github.com/rsachetto/MonoAlg3D_C/actions/workflows/build.yml/badge.svg)

The MonoAlg3D is a program for solving the 3D monodomain equation by applying the Finite Volume Method.

# Pre-Requisites

  - Linux-based operating system
  - Nvidia Driver 
  - CUDA library

### Setting the enviroment

Ubuntu: Refer to [the ubuntu guide](guide-monoalg3d-ubuntu.md)

Fedora: Refer to [the fedora guide](guide-monoalg3d-fedora.md)

### Compile
```sh
$ ./build.sh
```
The binary files will be saved in the ```bin``` folder.

# Running examples
```sh
$ bin/MonoAlg3D -c example_configs/cuboid_ohara.ini 
```

The output will be saved in the VTK format. In order to see the results you can use Paraview (https://www.paraview.org/) or the compiled visualization tool in ```bin/MonoAlg3D_visualizer```. You can also set the output to plain text, by changing the section ```save_result``` in example_configs/cuboid_ohara.ini to:

```ìni
[save_result]
print_rate=250
output_dir=./outputs/tmp_cube
main_function=save_as_text_or_binary
binary=false
```

In the plain text format we have:

- Each line represents a Volume
- Each volume is represented by its center point (X, Y, and Z), the value of half of its side length on x, y and z and the calculated V

Example file:

```
850,850,950,50,50,50, -85
850,950,950,50,50,50, -85
850,950,850,50,50,50, -85
```

This file represents 3 volumes with 100 micrometer of side. The first volume is centered at  at 850,850,950 and the calculated V is -85 mV.

# Contributors:

@rsachetto Rafael Sachetto Oliveira

@bergolho Lucas Arantes Berg

@Rodrigo-Weber-dos-Santos Rodrigo Weber dos Santos

Among others.

# How to cite:

For the updates made in Riebel et al., 2026:
Riebel LL, Wang ZJ, Zhou X, Berg LA, Trovato C, Rodriguez B. In silico optimization of regenerative cell therapy in the infarcted human ventricles to mitigate arrhythmic burden. Stem Cell Rep (2026). https://doi.org/10.1016/j.stemcr.2026.103007

For the updates made in Riebel et al., 2024:
Riebel LL, Wang ZJ, Martinez-Navarro H, Trovato C, Camps J, Berg LA, Zhou X, Doste R, Sachetto Oliveira R, Weber dos Santos R, Biasetti J, Rodriguez B. In Silico Evaluation of Cell Therapy in Acute versus Chronic Infarction: Role of Automaticity, Heterogeneity and Purkinje in Human. Sci Rep, 14 21584 (2024). https://doi.org/10.1038/s41598-024-67951-5

For MonoAlg3D:
Oliveira RS, Rocha BM, Burgarelli D, Meira Jr W, Constantinides C, dos Santos RW. Performance evaluation of GPU parallelization, space‐time adaptive algorithms, and their combination for simulating cardiac electrophysiology. Int J Numer Meth Biomed Engng. 2018;34:e2913. https://doi.org/10.1002/cnm.2913

# Credits
[Heart icons created by phatplus - Flaticon](https://www.flaticon.com/free-icons/heart)
