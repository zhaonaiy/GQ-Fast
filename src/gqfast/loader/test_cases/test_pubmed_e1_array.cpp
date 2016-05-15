#ifndef test_pubmed_e1_array_
#define test_pubmed_e1_array_

#include "../fastr_index.hpp"
#include "../global_vars.hpp"

#define NUM_THREADS 1
#define BUFFER_POOL_SIZE 1

using namespace std;

static int* R;
static int* RC;

extern inline void test_pubmed_e1_array_doc_col0_decode_UA(int32_t* doc_col0_ptr, int32_t doc_col0_bytes, int32_t & doc_fragment_size) __attribute__((always_inline));

void test_pubmed_e1_array_doc_col0_decode_UA(int32_t* doc_col0_ptr, int32_t doc_col0_bytes, int32_t & doc_fragment_size) {

	doc_fragment_size = doc_col0_bytes/4;

	for (int32_t i=0; i<doc_fragment_size; i++) {
		buffer_arrays[3][0][0][0][i] = *doc_col0_ptr++;
	}
}

extern "C" int* test_pubmed_e1_array(int** null_checks) {

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


	int64_t term_list[1];
	term_list[0] = 105;

	for (int term_it = 0; term_it<1; term_it++) {

		int64_t term_col0_element = term_list[term_it];

		uint32_t* row_doc = idx[3]->index_map[term_col0_element];
		int32_t doc_col0_bytes = idx[3]->index_map[term_col0_element+1][0] - row_doc[0];
		if(doc_col0_bytes) {

			int32_t* doc_col0_ptr = reinterpret_cast<int32_t *>(&(idx[3]->fragment_data[0][row_doc[0]]));
			int32_t doc_fragment_size = 0;
			test_pubmed_e1_array_doc_col0_decode_UA(doc_col0_ptr, doc_col0_bytes, doc_fragment_size);

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

