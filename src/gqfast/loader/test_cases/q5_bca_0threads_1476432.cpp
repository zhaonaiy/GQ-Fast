#ifndef q5_bca_0threads_1476432_
#define q5_bca_0threads_1476432_

#include "../fastr_index.hpp"
#include "../global_vars.hpp"


using namespace std;

static double* R;
static int* RC;

static uint64_t* doc1_col0_buffer;
static uint64_t* term_col0_buffer;
static uint64_t* term_col1_buffer;
static uint64_t* doc2_col0_buffer;
static uint64_t* doc2_col1_buffer;
static uint64_t* year_col0_buffer;
static uint64_t* author2_col0_buffer;

static uint32_t* doc1_col0_bits_info;
static uint64_t doc1_col0_offset;

static uint32_t* term_col0_bits_info;
static uint64_t term_col0_offset;

static uint32_t* term_col1_bits_info;
static uint64_t term_col1_offset;

static uint32_t* doc2_col0_bits_info;
static uint64_t doc2_col0_offset;

static uint32_t* doc2_col1_bits_info;
static uint64_t doc2_col1_offset;

static uint32_t* year_col0_bits_info;
static uint64_t year_col0_offset;

static uint32_t* author2_col0_bits_info;
static uint64_t author2_col0_offset;

extern inline void q5_bca_0threads_1476432_doc1_col0_decode_BCA(unsigned char* doc1_col0_ptr, uint32_t doc1_col0_bytes, uint32_t & doc1_fragment_size) __attribute__((always_inline));

extern inline void q5_bca_0threads_1476432_term_col0_decode_BCA(unsigned char* term_col0_ptr, uint32_t term_col0_bytes, uint32_t & term_fragment_size) __attribute__((always_inline));

extern inline void q5_bca_0threads_1476432_term_col1_decode_BCA(unsigned char* term_col1_ptr, uint32_t term_fragment_size) __attribute__((always_inline));

extern inline void q5_bca_0threads_1476432_doc2_col0_decode_BCA(unsigned char* doc2_col0_ptr, uint32_t doc2_col0_bytes, uint32_t & doc2_fragment_size) __attribute__((always_inline));

extern inline void q5_bca_0threads_1476432_doc2_col1_decode_BCA(unsigned char* doc2_col1_ptr, uint32_t doc2_fragment_size) __attribute__((always_inline));

extern inline void q5_bca_0threads_1476432_year_col0_decode_BCA(uint64_t* year_col0_ptr, uint32_t & year_col0_element) __attribute__((always_inline));

extern inline void q5_bca_0threads_1476432_author2_col0_decode_BCA(unsigned char* author2_col0_ptr, uint32_t author2_col0_bytes, uint32_t & author2_fragment_size) __attribute__((always_inline));

void q5_bca_0threads_1476432_doc1_col0_decode_BCA(unsigned char* doc1_col0_ptr, uint32_t doc1_col0_bytes, uint32_t & doc1_fragment_size) {

	doc1_fragment_size = doc1_col0_bytes* 8 / doc1_col0_bits_info[0];
	int bit_pos = 0;
	for (uint32_t i=0; i<doc1_fragment_size; i++) {
		uint32_t encoded_value = doc1_col0_bits_info[1] << bit_pos;
		uint64_t * next_8_ptr = reinterpret_cast<uint64_t *>(doc1_col0_ptr);
		encoded_value &= *next_8_ptr;
		encoded_value >>= bit_pos;

		doc1_col0_ptr += (bit_pos + doc1_col0_bits_info[0]) / 8;
		bit_pos = (bit_pos + doc1_col0_bits_info[0]) % 8;
		doc1_col0_buffer[i] = encoded_value + doc1_col0_offset;
	}
}

void q5_bca_0threads_1476432_term_col0_decode_BCA(unsigned char* term_col0_ptr, uint32_t term_col0_bytes, uint32_t & term_fragment_size) {

	term_fragment_size = term_col0_bytes* 8 / term_col0_bits_info[0];
	int bit_pos = 0;
	for (uint32_t i=0; i<term_fragment_size; i++) {
		uint32_t encoded_value = term_col0_bits_info[1] << bit_pos;
		uint64_t * next_8_ptr = reinterpret_cast<uint64_t *>(term_col0_ptr);
		encoded_value &= *next_8_ptr;
		encoded_value >>= bit_pos;

		term_col0_ptr += (bit_pos + term_col0_bits_info[0]) / 8;
		bit_pos = (bit_pos + term_col0_bits_info[0]) % 8;
		term_col0_buffer[i] = encoded_value + term_col0_offset;
	}
}

void q5_bca_0threads_1476432_term_col1_decode_BCA(unsigned char* term_col1_ptr, uint32_t term_fragment_size) {

	int bit_pos = 0;
	for (uint32_t i=0; i<term_fragment_size; i++) {
		uint32_t encoded_value = term_col1_bits_info[1] << bit_pos;
		uint64_t * next_8_ptr = reinterpret_cast<uint64_t *>(term_col1_ptr);
		encoded_value &= *next_8_ptr;
		encoded_value >>= bit_pos;

		term_col1_ptr += (bit_pos + term_col1_bits_info[0]) / 8;
		bit_pos = (bit_pos + term_col1_bits_info[0]) % 8;
		term_col1_buffer[i] = encoded_value + term_col1_offset;
	}
}

void q5_bca_0threads_1476432_doc2_col0_decode_BCA(unsigned char* doc2_col0_ptr, uint32_t doc2_col0_bytes, uint32_t & doc2_fragment_size) {

	doc2_fragment_size = doc2_col0_bytes* 8 / doc2_col0_bits_info[0];
	int bit_pos = 0;
	for (uint32_t i=0; i<doc2_fragment_size; i++) {
		uint32_t encoded_value = doc2_col0_bits_info[1] << bit_pos;
		uint64_t * next_8_ptr = reinterpret_cast<uint64_t *>(doc2_col0_ptr);
		encoded_value &= *next_8_ptr;
		encoded_value >>= bit_pos;

		doc2_col0_ptr += (bit_pos + doc2_col0_bits_info[0]) / 8;
		bit_pos = (bit_pos + doc2_col0_bits_info[0]) % 8;
		doc2_col0_buffer[i] = encoded_value + doc2_col0_offset;
	}
}

void q5_bca_0threads_1476432_doc2_col1_decode_BCA(unsigned char* doc2_col1_ptr, uint32_t doc2_fragment_size) {

	int bit_pos = 0;
	for (uint32_t i=0; i<doc2_fragment_size; i++) {
		uint32_t encoded_value = doc2_col1_bits_info[1] << bit_pos;
		uint64_t * next_8_ptr = reinterpret_cast<uint64_t *>(doc2_col1_ptr);
		encoded_value &= *next_8_ptr;
		encoded_value >>= bit_pos;

		doc2_col1_ptr += (bit_pos + doc2_col1_bits_info[0]) / 8;
		bit_pos = (bit_pos + doc2_col1_bits_info[0]) % 8;
		doc2_col1_buffer[i] = encoded_value + doc2_col1_offset;
	}
}

void q5_bca_0threads_1476432_year_col0_decode_BCA(uint64_t* year_col0_ptr, uint32_t & year_col0_element) {

	year_col0_element = year_col0_bits_info[1];
	year_col0_element &= *year_col0_ptr;
	year_col0_element += year_col0_offset;
}

void q5_bca_0threads_1476432_author2_col0_decode_BCA(unsigned char* author2_col0_ptr, uint32_t author2_col0_bytes, uint32_t & author2_fragment_size) {

	author2_fragment_size = author2_col0_bytes* 8 / author2_col0_bits_info[0];
	int bit_pos = 0;
	for (uint32_t i=0; i<author2_fragment_size; i++) {
		uint32_t encoded_value = author2_col0_bits_info[1] << bit_pos;
		uint64_t * next_8_ptr = reinterpret_cast<uint64_t *>(author2_col0_ptr);
		encoded_value &= *next_8_ptr;
		encoded_value >>= bit_pos;

		author2_col0_ptr += (bit_pos + author2_col0_bits_info[0]) / 8;
		bit_pos = (bit_pos + author2_col0_bits_info[0]) % 8;
		author2_col0_buffer[i] = encoded_value + author2_col0_offset;
	}
}

extern "C" double* q5_bca_0threads_1476432(int** null_checks) {

	benchmark_t1 = chrono::steady_clock::now();

	int max_frag;

	max_frag = metadata.idx_max_fragment_sizes[0];
	doc1_col0_buffer = new uint64_t[max_frag];

	max_frag = metadata.idx_max_fragment_sizes[2];
	term_col0_buffer = new uint64_t[max_frag];
	term_col1_buffer = new uint64_t[max_frag];

	max_frag = metadata.idx_max_fragment_sizes[3];
	doc2_col0_buffer = new uint64_t[max_frag];
	doc2_col1_buffer = new uint64_t[max_frag];

	max_frag = metadata.idx_max_fragment_sizes[1];
	year_col0_buffer = new uint64_t[max_frag];

	max_frag = metadata.idx_max_fragment_sizes[4];
	author2_col0_buffer = new uint64_t[max_frag];

	RC = new int[metadata.idx_domains[4][0]]();
	R = new double[metadata.idx_domains[4][0]]();


	doc1_col0_bits_info = idx[0]->dict[0]->bits_info;
	doc1_col0_offset = idx[0]->dict[0]->offset;

	term_col0_bits_info = idx[2]->dict[0]->bits_info;
	term_col0_offset = idx[2]->dict[0]->offset;

	term_col1_bits_info = idx[2]->dict[1]->bits_info;
	term_col1_offset = idx[2]->dict[1]->offset;

	doc2_col0_bits_info = idx[3]->dict[0]->bits_info;
	doc2_col0_offset = idx[3]->dict[0]->offset;

	doc2_col1_bits_info = idx[3]->dict[1]->bits_info;
	doc2_col1_offset = idx[3]->dict[1]->offset;

	year_col0_bits_info = idx[1]->dict[0]->bits_info;
	year_col0_offset = idx[1]->dict[0]->offset;

	author2_col0_bits_info = idx[4]->dict[0]->bits_info;
	author2_col0_offset = idx[4]->dict[0]->offset;

	uint64_t author1_list[1];
	author1_list[0] = 1476432;

	for (int author1_it = 0; author1_it<1; author1_it++) {

		uint64_t author1_col0_element = author1_list[author1_it];

		uint32_t* row_doc1 = idx[0]->index_map[author1_col0_element];
		uint32_t doc1_col0_bytes = idx[0]->index_map[author1_col0_element+1][0] - row_doc1[0];
		if(doc1_col0_bytes) {

			unsigned char* doc1_col0_ptr = &(idx[0]->fragment_data[0][row_doc1[0]]);
			uint32_t doc1_fragment_size = 0;
			q5_bca_0threads_1476432_doc1_col0_decode_BCA(doc1_col0_ptr, doc1_col0_bytes, doc1_fragment_size);

			for (uint32_t doc1_it = 0; doc1_it < doc1_fragment_size; doc1_it++) {

				uint32_t doc1_col0_element = doc1_col0_buffer[doc1_it];

				uint32_t* row_term = idx[2]->index_map[doc1_col0_element];
				uint32_t term_col0_bytes = idx[2]->index_map[doc1_col0_element+1][0] - row_term[0];
				if(term_col0_bytes) {

					unsigned char* term_col0_ptr = &(idx[2]->fragment_data[0][row_term[0]]);
					uint32_t term_fragment_size = 0;
					q5_bca_0threads_1476432_term_col0_decode_BCA(term_col0_ptr, term_col0_bytes, term_fragment_size);

					unsigned char* term_col1_ptr = &(idx[2]->fragment_data[1][row_term[1]]);
					q5_bca_0threads_1476432_term_col1_decode_BCA(term_col1_ptr, term_fragment_size);

					for (uint32_t term_it = 0; term_it < term_fragment_size; term_it++) {

						uint32_t term_col0_element = term_col0_buffer[term_it];
						unsigned char term_col1_element = term_col1_buffer[term_it];

						uint32_t* row_doc2 = idx[3]->index_map[term_col0_element];
						uint32_t doc2_col0_bytes = idx[3]->index_map[term_col0_element+1][0] - row_doc2[0];
						if(doc2_col0_bytes) {

							unsigned char* doc2_col0_ptr = &(idx[3]->fragment_data[0][row_doc2[0]]);
							uint32_t doc2_fragment_size = 0;
							q5_bca_0threads_1476432_doc2_col0_decode_BCA(doc2_col0_ptr, doc2_col0_bytes, doc2_fragment_size);

							unsigned char* doc2_col1_ptr = &(idx[3]->fragment_data[1][row_doc2[1]]);
							q5_bca_0threads_1476432_doc2_col1_decode_BCA(doc2_col1_ptr, doc2_fragment_size);

							for (uint32_t doc2_it = 0; doc2_it < doc2_fragment_size; doc2_it++) {

								uint32_t doc2_col0_element = doc2_col0_buffer[doc2_it];
								unsigned char doc2_col1_element = doc2_col1_buffer[doc2_it];

								uint32_t* row_year = idx[1]->index_map[doc2_col0_element];

								uint64_t* year_col0_ptr = reinterpret_cast<uint64_t *>(&(idx[1]->fragment_data[0][row_year[0]]));
								uint32_t year_col0_element;
								q5_bca_0threads_1476432_year_col0_decode_BCA(year_col0_ptr, year_col0_element);

								uint32_t* row_author2 = idx[4]->index_map[doc2_col0_element];
								uint32_t author2_col0_bytes = idx[4]->index_map[doc2_col0_element+1][0] - row_author2[0];
								if(author2_col0_bytes) {

									unsigned char* author2_col0_ptr = &(idx[4]->fragment_data[0][row_author2[0]]);
									uint32_t author2_fragment_size = 0;
									q5_bca_0threads_1476432_author2_col0_decode_BCA(author2_col0_ptr, author2_col0_bytes, author2_fragment_size);

									for (uint32_t author2_it = 0; author2_it < author2_fragment_size; author2_it++) {
										uint32_t author2_col0_element = author2_col0_buffer[author2_it];

										RC[author2_col0_element] = 1;
										R[author2_col0_element] += (double)(term_col1_element*doc2_col1_element)/(2017-year_col0_element);
									}
								}
							}
						}
					}
				}
			}
		}
	}


	delete[] doc1_col0_buffer;
	delete[] term_col0_buffer;
	delete[] term_col1_buffer;
	delete[] doc2_col0_buffer;
	delete[] doc2_col1_buffer;
	delete[] year_col0_buffer;
	delete[] author2_col0_buffer;


	*null_checks = RC;
	return R;

}

#endif
