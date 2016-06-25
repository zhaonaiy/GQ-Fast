#ifndef q1_opt_0threads_18681952_
#define q1_opt_0threads_18681952_

#include "../fastr_index.hpp"
#include "../global_vars.hpp"


using namespace std;

static int* R;
static int* RC;

static uint64_t* term1_col0_buffer;
static uint64_t* doc2_col0_buffer;

extern inline void q1_opt_0threads_18681952_term1_col0_decode_BB(unsigned char* term1_col0_ptr, uint32_t term1_col0_bytes, uint32_t & term1_fragment_size) __attribute__((always_inline));

extern inline void q1_opt_0threads_18681952_doc2_col0_decode_BB(unsigned char* doc2_col0_ptr, uint32_t doc2_col0_bytes, uint32_t & doc2_fragment_size) __attribute__((always_inline));

void q1_opt_0threads_18681952_term1_col0_decode_BB(unsigned char* term1_col0_ptr, uint32_t term1_col0_bytes, uint32_t & term1_fragment_size) {

	term1_col0_buffer[0] = 0;

	int shiftbits = 0;
	do { 
		term1_col0_bytes--;
		uint32_t next_seven_bits = *term1_col0_ptr & 127;
		next_seven_bits = next_seven_bits << shiftbits;
		term1_col0_buffer[0] |= next_seven_bits;
		shiftbits += 7;
	} while (!(*term1_col0_ptr++ & 128));
	term1_fragment_size++;

	while (term1_col0_bytes > 0) {
		shiftbits = 0;
		uint32_t result = 0;

		do {

			term1_col0_bytes--;
			uint32_t next_seven_bits = *term1_col0_ptr & 127;
			next_seven_bits = next_seven_bits << shiftbits;
			result |= next_seven_bits;
			shiftbits += 7;

		} while (!(*term1_col0_ptr++ & 128));
		term1_col0_buffer[term1_fragment_size] = term1_col0_buffer[term1_fragment_size-1]+1+result;
		term1_fragment_size++;
	}
}

void q1_opt_0threads_18681952_doc2_col0_decode_BB(unsigned char* doc2_col0_ptr, uint32_t doc2_col0_bytes, uint32_t & doc2_fragment_size) {

	doc2_col0_buffer[0] = 0;

	int shiftbits = 0;
	do { 
		doc2_col0_bytes--;
		uint32_t next_seven_bits = *doc2_col0_ptr & 127;
		next_seven_bits = next_seven_bits << shiftbits;
		doc2_col0_buffer[0] |= next_seven_bits;
		shiftbits += 7;
	} while (!(*doc2_col0_ptr++ & 128));
	doc2_fragment_size++;

	while (doc2_col0_bytes > 0) {
		shiftbits = 0;
		uint32_t result = 0;

		do {

			doc2_col0_bytes--;
			uint32_t next_seven_bits = *doc2_col0_ptr & 127;
			next_seven_bits = next_seven_bits << shiftbits;
			result |= next_seven_bits;
			shiftbits += 7;

		} while (!(*doc2_col0_ptr++ & 128));
		doc2_col0_buffer[doc2_fragment_size] = doc2_col0_buffer[doc2_fragment_size-1]+1+result;
		doc2_fragment_size++;
	}
}

extern "C" int* q1_opt_0threads_18681952(int** null_checks) {

	benchmark_t1 = chrono::steady_clock::now();

	int max_frag;

	max_frag = metadata.idx_max_fragment_sizes[2];
	term1_col0_buffer = new uint64_t[max_frag];

	max_frag = metadata.idx_max_fragment_sizes[3];
	doc2_col0_buffer = new uint64_t[max_frag];

	RC = new int[metadata.idx_domains[3][0]]();
	R = new int[metadata.idx_domains[3][0]]();


	uint64_t doc1_list[1];
	doc1_list[0] = 18681952;

	for (int doc1_it = 0; doc1_it<1; doc1_it++) {

		uint64_t doc1_col0_element = doc1_list[doc1_it];

		uint32_t* row_term1 = idx[2]->index_map[doc1_col0_element];
		uint32_t term1_col0_bytes = idx[2]->index_map[doc1_col0_element+1][0] - row_term1[0];
		if(term1_col0_bytes) {

			unsigned char* term1_col0_ptr = &(idx[2]->fragment_data[0][row_term1[0]]);
			uint32_t term1_fragment_size = 0;
			q1_opt_0threads_18681952_term1_col0_decode_BB(term1_col0_ptr, term1_col0_bytes, term1_fragment_size);

			for (uint32_t term1_it = 0; term1_it < term1_fragment_size; term1_it++) {

				uint32_t term1_col0_element = term1_col0_buffer[term1_it];

				uint32_t* row_doc2 = idx[3]->index_map[term1_col0_element];
				uint32_t doc2_col0_bytes = idx[3]->index_map[term1_col0_element+1][0] - row_doc2[0];
				if(doc2_col0_bytes) {

					unsigned char* doc2_col0_ptr = &(idx[3]->fragment_data[0][row_doc2[0]]);
					uint32_t doc2_fragment_size = 0;
					q1_opt_0threads_18681952_doc2_col0_decode_BB(doc2_col0_ptr, doc2_col0_bytes, doc2_fragment_size);

					for (uint32_t doc2_it = 0; doc2_it < doc2_fragment_size; doc2_it++) {
						uint32_t doc2_col0_element = doc2_col0_buffer[doc2_it];

						RC[doc2_col0_element] = 1;
						R[doc2_col0_element] += 1;
					}
				}
			}
		}
	}


	delete[] term1_col0_buffer;
	delete[] doc2_col0_buffer;


	*null_checks = RC;
	return R;

}

#endif
