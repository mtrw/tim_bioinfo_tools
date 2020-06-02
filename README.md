# tim_bioinfo_tools
A miscellaneous collection of useful bioinformatics tools


#################### blast_get_alleles_at_position.c ####################

Retrieve the alleles at a given position from BLAST-style alignment strings

Notes:
-Must be compiled
-The returned nucleotides are given directly from the string, therefore, if the subject sequence is reversed and the subject state is desired as it occurs in the subject sequence blasted, then the retrieved nucleotides must be subsequently reverse-complemented 

USAGE: blast_get_alleles_at_position.exe <start position of string 1> <direction of string 1 (1|-1)> <string 1> <start position of string 2> <direction of string 2 (1|-1)> <string 2> <desired position to retrieve on string 1>
EXAMPLE: blast_get_alleles_at_position.exe 10 -1 AGTC-A 1 1 2 AGTTGA 9

#################### blast_to_snps.c ####################

Extract non-matching sites and their positions between BLAST-style alignment strings

Notes:
-Must be compiled
-The returned nucleotides are given directly from the string, therefore, if the subject sequence is reversed and the subject state is desired as it occurs in the subject sequence blasted, then the retrieved nucleotides must be subsequently reverse-complemented
-Will not return a difference if it occurs adjacent to a gap position on either alignment, i.e. AGCT-A vs A-CTGA will return no differences.

USAGE: blast_to_snps.c <start position of string 1> <direction of string 1 (1|-1)> <string 1> <start position of string 2> <direction of string 2 (1|-1)> <string 2>
EXAMPLE: blast_to_snps.c 10 -1 AGTC-A 1 1 2 AGTTGA 9

