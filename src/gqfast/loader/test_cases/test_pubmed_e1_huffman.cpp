#ifndef test_pubmed_e1_huffman_
#define test_pubmed_e1_huffman_

#include "../fastr_index.hpp"
#include "../global_vars.hpp"

#define NUM_THREADS 1
#define BUFFER_POOL_SIZE 1

using namespace std;

static int* R;
static int* RC;

static int* doc_col0_huffman_tree_array;
static bool* doc_col0_huffman_terminator_array;

extern inline void test_pubmed_e1_huffman_doc_col0_decode_Huffman(unsigned char* doc_col0_ptr, int32_t doc_col0_bytes, int32_t & doc_fragment_size) __attribute__((always_inline));

void test_pubmed_e1_huffman_doc_col0_decode_Huffman(unsigned char* doc_col0_ptr, int32_t doc_col0_bytes, int32_t & doc_fragment_size) {

	bool* terminate_start = &(doc_col0_huffman_terminator_array[0]);
	int* tree_array_start = &(doc_col0_huffman_tree_array[0]);

	int mask = 0x100;

	while (doc_col0_bytes > 1) {

		bool* terminator_array = terminate_start;
		int* tree_array = tree_array_start;

		while(!*terminator_array) { 

			char direction = *doc_col0_ptr & (mask >>= 1);

			if (mask == 1) { 
				mask = 0x100;
				doc_col0_ptr++;
				doc_col0_bytes--;
			}

			terminator_array += *tree_array;
			tree_array += *tree_array;

			if (direction) {
				terminator_array++;
				tree_array++;
			}
		}

		buffer_arrays[3][0][0][0][doc_fragment_size++] = *tree_array;
	}

	if (mask != 0x100) {
		int bit_pos = mask;
		unsigned char last_byte = *doc_col0_ptr;
		while (bit_pos > 1) {
			unsigned char bit = last_byte & (bit_pos >>= 1);
			if (bit) {
				bool* terminator_array = terminate_start;
				int* tree_array = tree_array_start;

				while (!*terminator_array) {
					char direction = *doc_col0_ptr & (mask >>= 1);

					terminator_array += *tree_array;
					tree_array += *tree_array;

					if (direction) {
						terminator_array++;
						tree_array++;
					}
				}

				buffer_arrays[3][0][0][0][doc_fragment_size++] = *tree_array;
				bit_pos = mask;
			}
		}
	}
}

extern "C" int* test_pubmed_e1_huffman(int** null_checks) {

	benchmark_t1 = chrono::steady_clock::now();

	int max_frag;

	max_frag = metadata.idx_max_fragment_sizes[3];
	for(int i=0; i<metadata.idx_num_encodings[3]; i++) {
		for (int j=0; j<NUM_THREADS; j++) {
			buffer_arrays[3][i][j] = new int*[BUFFER_POOL_SIZE];
			for (int k=0; k<BUFFER_POOL_SIZE; k++) {
				buffer_arrays[3][i][j][k] = new int[max_frag];
			}
		}
	}

	RC = new int[metadata.idx_domains[3][0]]();
	R = new int[metadata.idx_domains[3][0]]();


	doc_col0_huffman_tree_array = idx[3]->huffman_tree_array[0];
	doc_col0_huffman_terminator_array = idx[3]->huffman_terminator_array[0];

	int64_t term_list[1];
	term_list[0] = 105;

	for (int term_it = 0; term_it<1; term_it++) {

		int64_t term_col0_element = term_list[term_it];

		uint32_t* row_doc = idx[3]->index_map[term_col0_element];
		int32_t doc_col0_bytes = idx[3]->index_map[term_col0_element+1][0] - row_doc[0];
		if(doc_col0_bytes) {

			unsigned char* doc_col0_ptr = &(idx[3]->fragment_data[0][row_doc[0]]);
			int32_t doc_fragment_size = 0;
			test_pubmed_e1_huffman_doc_col0_decode_Huffman(doc_col0_ptr, doc_col0_bytes, doc_fragment_size);

			for (int32_t doc_it = 0; doc_it < doc_fragment_size; doc_it++) {
				uint32_t doc_col0_element = buffer_arrays[3][0][0][0][doc_it];

				RC[doc_col0_element] = 1;
				R[doc_col0_element] = 1;
			}
		}
	}


	for (int j=0; j<metadata.idx_num_encodings[3]; j++) {
		for (int k=0; k<NUM_THREADS; k++) {
			for (int l=0; l<BUFFER_POOL_SIZE; l++) {
				delete[] buffer_arrays[3][j][k][l];
			}
			delete[] buffer_arrays[3][j][k];
		}
	}


	*null_checks = RC;
	return R;

}

#endif
