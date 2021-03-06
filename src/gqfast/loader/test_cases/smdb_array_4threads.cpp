#ifndef smdb_array_4threads_
#define smdb_array_4threads_

#include "../fastr_index.hpp"
#include "../global_vars.hpp"

#include <atomic>
#define NUM_THREADS 4

using namespace std;

static args_threading arguments[NUM_THREADS];


static int* R;
static int* RC;

static pthread_spinlock_t* r_spin_locks;

static uint64_t** concept_semtype1_col0_buffer;
static uint64_t** predication1_col0_buffer;
static uint64_t** sentence1_col0_buffer;
static uint64_t** predication2_col0_buffer;
static uint64_t** concept_semtype2_col0_buffer;
static uint64_t** concept2_col0_buffer;

static atomic<bool>* sentence1_bool_array;
static pthread_spinlock_t* sentence1_spin_lock;

extern inline void smdb_array_4threads_concept_semtype1_col0_decode_UA(uint32_t* concept_semtype1_col0_ptr, uint32_t concept_semtype1_col0_bytes, uint32_t & concept_semtype1_fragment_size) __attribute__((always_inline));

void* pthread_smdb_array_4threads_worker(void* arguments);

extern inline void smdb_array_4threads_predication1_col0_decode_UA_threaded(int thread_id, uint32_t* predication1_col0_ptr, uint32_t predication1_col0_bytes, uint32_t & predication1_fragment_size) __attribute__((always_inline));

extern inline void smdb_array_4threads_sentence1_col0_decode_UA_threaded(int thread_id, uint32_t* sentence1_col0_ptr, uint32_t sentence1_col0_bytes, uint32_t & sentence1_fragment_size) __attribute__((always_inline));

extern inline void smdb_array_4threads_predication2_col0_decode_UA_threaded(int thread_id, uint32_t* predication2_col0_ptr, uint32_t predication2_col0_bytes, uint32_t & predication2_fragment_size) __attribute__((always_inline));

extern inline void smdb_array_4threads_concept_semtype2_col0_decode_UA_threaded(int thread_id, uint32_t* concept_semtype2_col0_ptr, uint32_t concept_semtype2_col0_bytes, uint32_t & concept_semtype2_fragment_size) __attribute__((always_inline));

extern inline void smdb_array_4threads_concept2_col0_decode_UA_threaded(int thread_id, uint32_t* concept2_col0_ptr, uint32_t concept2_col0_bytes, uint32_t & concept2_fragment_size) __attribute__((always_inline));

void smdb_array_4threads_concept_semtype1_col0_decode_UA(uint32_t* concept_semtype1_col0_ptr, uint32_t concept_semtype1_col0_bytes, uint32_t & concept_semtype1_fragment_size) {

	concept_semtype1_fragment_size = concept_semtype1_col0_bytes/4;

	for (uint32_t i=0; i<concept_semtype1_fragment_size; i++) {
		concept_semtype1_col0_buffer[0][i] = *concept_semtype1_col0_ptr++;
	}
}

void* pthread_smdb_array_4threads_worker(void* arguments) {

	args_threading* args = (args_threading *) arguments;

	uint32_t concept_semtype1_it = args->start;
	uint32_t concept_semtype1_fragment_size = args->end;
	int thread_id = args->thread_id;

	for (; concept_semtype1_it < concept_semtype1_fragment_size; concept_semtype1_it++) {

		uint32_t concept_semtype1_col0_element = concept_semtype1_col0_buffer[0][concept_semtype1_it];

		uint32_t* row_predication1 = idx[1]->index_map[concept_semtype1_col0_element];
		uint32_t predication1_col0_bytes = idx[1]->index_map[concept_semtype1_col0_element+1][0] - row_predication1[0];
		if(predication1_col0_bytes) {

			uint32_t* predication1_col0_ptr = reinterpret_cast<uint32_t *>(&(idx[1]->fragment_data[0][row_predication1[0]]));
			uint32_t predication1_fragment_size = 0;
			smdb_array_4threads_predication1_col0_decode_UA_threaded(thread_id, predication1_col0_ptr, predication1_col0_bytes, predication1_fragment_size);

			for (uint32_t predication1_it = 0; predication1_it < predication1_fragment_size; predication1_it++) {

				uint32_t predication1_col0_element = predication1_col0_buffer[thread_id][predication1_it];

				uint32_t* row_sentence1 = idx[2]->index_map[predication1_col0_element];
				uint32_t sentence1_col0_bytes = idx[2]->index_map[predication1_col0_element+1][0] - row_sentence1[0];
				if(sentence1_col0_bytes) {

					uint32_t* sentence1_col0_ptr = reinterpret_cast<uint32_t *>(&(idx[2]->fragment_data[0][row_sentence1[0]]));
					uint32_t sentence1_fragment_size = 0;
					smdb_array_4threads_sentence1_col0_decode_UA_threaded(thread_id, sentence1_col0_ptr, sentence1_col0_bytes, sentence1_fragment_size);

					for (uint32_t sentence1_it = 0; sentence1_it < sentence1_fragment_size; sentence1_it++) {


						if (!(sentence1_bool_array[sentence1_col0_buffer[thread_id][sentence1_it]])) {
							sentence1_bool_array[sentence1_col0_buffer[thread_id][sentence1_it]] = true;
							uint32_t sentence1_col0_element = sentence1_col0_buffer[thread_id][sentence1_it];

							uint32_t* row_predication2 = idx[3]->index_map[sentence1_col0_element];
							uint32_t predication2_col0_bytes = idx[3]->index_map[sentence1_col0_element+1][0] - row_predication2[0];
							if(predication2_col0_bytes) {

								uint32_t* predication2_col0_ptr = reinterpret_cast<uint32_t *>(&(idx[3]->fragment_data[0][row_predication2[0]]));
								uint32_t predication2_fragment_size = 0;
								smdb_array_4threads_predication2_col0_decode_UA_threaded(thread_id, predication2_col0_ptr, predication2_col0_bytes, predication2_fragment_size);

								for (uint32_t predication2_it = 0; predication2_it < predication2_fragment_size; predication2_it++) {

									uint32_t predication2_col0_element = predication2_col0_buffer[thread_id][predication2_it];

									uint32_t* row_concept_semtype2 = idx[4]->index_map[predication2_col0_element];
									uint32_t concept_semtype2_col0_bytes = idx[4]->index_map[predication2_col0_element+1][0] - row_concept_semtype2[0];
									if(concept_semtype2_col0_bytes) {

										uint32_t* concept_semtype2_col0_ptr = reinterpret_cast<uint32_t *>(&(idx[4]->fragment_data[0][row_concept_semtype2[0]]));
										uint32_t concept_semtype2_fragment_size = 0;
										smdb_array_4threads_concept_semtype2_col0_decode_UA_threaded(thread_id, concept_semtype2_col0_ptr, concept_semtype2_col0_bytes, concept_semtype2_fragment_size);

										for (uint32_t concept_semtype2_it = 0; concept_semtype2_it < concept_semtype2_fragment_size; concept_semtype2_it++) {

											uint32_t concept_semtype2_col0_element = concept_semtype2_col0_buffer[thread_id][concept_semtype2_it];

											uint32_t* row_concept2 = idx[5]->index_map[concept_semtype2_col0_element];
											uint32_t concept2_col0_bytes = idx[5]->index_map[concept_semtype2_col0_element+1][0] - row_concept2[0];
											if(concept2_col0_bytes) {

												uint32_t* concept2_col0_ptr = reinterpret_cast<uint32_t *>(&(idx[5]->fragment_data[0][row_concept2[0]]));
												uint32_t concept2_fragment_size = 0;
												smdb_array_4threads_concept2_col0_decode_UA_threaded(thread_id, concept2_col0_ptr, concept2_col0_bytes, concept2_fragment_size);

												for (uint32_t concept2_it = 0; concept2_it < concept2_fragment_size; concept2_it++) {
													uint32_t concept2_col0_element = concept2_col0_buffer[thread_id][concept2_it];

													RC[concept2_col0_element] = 1;

													pthread_spin_lock(&r_spin_locks[concept2_col0_element]);
													R[concept2_col0_element] += 1;
													pthread_spin_unlock(&r_spin_locks[concept2_col0_element]);

												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return nullptr;
}

void smdb_array_4threads_predication1_col0_decode_UA_threaded(int thread_id, uint32_t* predication1_col0_ptr, uint32_t predication1_col0_bytes, uint32_t & predication1_fragment_size) {

	predication1_fragment_size = predication1_col0_bytes/4;

	for (uint32_t i=0; i<predication1_fragment_size; i++) {
		predication1_col0_buffer[thread_id][i] = *predication1_col0_ptr++;
	}
}

void smdb_array_4threads_sentence1_col0_decode_UA_threaded(int thread_id, uint32_t* sentence1_col0_ptr, uint32_t sentence1_col0_bytes, uint32_t & sentence1_fragment_size) {

	sentence1_fragment_size = sentence1_col0_bytes/4;

	for (uint32_t i=0; i<sentence1_fragment_size; i++) {
		sentence1_col0_buffer[thread_id][i] = *sentence1_col0_ptr++;
	}
}

void smdb_array_4threads_predication2_col0_decode_UA_threaded(int thread_id, uint32_t* predication2_col0_ptr, uint32_t predication2_col0_bytes, uint32_t & predication2_fragment_size) {

	predication2_fragment_size = predication2_col0_bytes/4;

	for (uint32_t i=0; i<predication2_fragment_size; i++) {
		predication2_col0_buffer[thread_id][i] = *predication2_col0_ptr++;
	}
}

void smdb_array_4threads_concept_semtype2_col0_decode_UA_threaded(int thread_id, uint32_t* concept_semtype2_col0_ptr, uint32_t concept_semtype2_col0_bytes, uint32_t & concept_semtype2_fragment_size) {

	concept_semtype2_fragment_size = concept_semtype2_col0_bytes/4;

	for (uint32_t i=0; i<concept_semtype2_fragment_size; i++) {
		concept_semtype2_col0_buffer[thread_id][i] = *concept_semtype2_col0_ptr++;
	}
}

void smdb_array_4threads_concept2_col0_decode_UA_threaded(int thread_id, uint32_t* concept2_col0_ptr, uint32_t concept2_col0_bytes, uint32_t & concept2_fragment_size) {

	concept2_fragment_size = concept2_col0_bytes/4;

	for (uint32_t i=0; i<concept2_fragment_size; i++) {
		concept2_col0_buffer[thread_id][i] = *concept2_col0_ptr++;
	}
}

extern "C" int* smdb_array_4threads(int** null_checks) {

	benchmark_t1 = chrono::steady_clock::now();

	int max_frag;

	max_frag = metadata.idx_max_fragment_sizes[0];
	concept_semtype1_col0_buffer = new uint64_t*[NUM_THREADS];
	for (int i=0; i<NUM_THREADS; i++) {
		concept_semtype1_col0_buffer[i] = new uint64_t[max_frag];
	}

	max_frag = metadata.idx_max_fragment_sizes[1];
	predication1_col0_buffer = new uint64_t*[NUM_THREADS];
	for (int i=0; i<NUM_THREADS; i++) {
		predication1_col0_buffer[i] = new uint64_t[max_frag];
	}

	max_frag = metadata.idx_max_fragment_sizes[2];
	sentence1_col0_buffer = new uint64_t*[NUM_THREADS];
	for (int i=0; i<NUM_THREADS; i++) {
		sentence1_col0_buffer[i] = new uint64_t[max_frag];
	}

	max_frag = metadata.idx_max_fragment_sizes[3];
	predication2_col0_buffer = new uint64_t*[NUM_THREADS];
	for (int i=0; i<NUM_THREADS; i++) {
		predication2_col0_buffer[i] = new uint64_t[max_frag];
	}

	max_frag = metadata.idx_max_fragment_sizes[4];
	concept_semtype2_col0_buffer = new uint64_t*[NUM_THREADS];
	for (int i=0; i<NUM_THREADS; i++) {
		concept_semtype2_col0_buffer[i] = new uint64_t[max_frag];
	}

	max_frag = metadata.idx_max_fragment_sizes[5];
	concept2_col0_buffer = new uint64_t*[NUM_THREADS];
	for (int i=0; i<NUM_THREADS; i++) {
		concept2_col0_buffer[i] = new uint64_t[max_frag];
	}

	RC = new int[metadata.idx_domains[5][0]]();
	R = new int[metadata.idx_domains[5][0]]();

	r_spin_locks = spin_locks[5];

	uint64_t sentence1_domain = metadata.idx_domains[2][0];
	sentence1_bool_array = new atomic<bool>[sentence1_domain]();

	uint64_t concept1_list[1];
	concept1_list[0] = 2019;

	for (int concept1_it = 0; concept1_it<1; concept1_it++) {

		uint64_t concept1_col0_element = concept1_list[concept1_it];

		uint32_t* row_concept_semtype1 = idx[0]->index_map[concept1_col0_element];
		uint32_t concept_semtype1_col0_bytes = idx[0]->index_map[concept1_col0_element+1][0] - row_concept_semtype1[0];
		if(concept_semtype1_col0_bytes) {

			uint32_t* concept_semtype1_col0_ptr = reinterpret_cast<uint32_t *>(&(idx[0]->fragment_data[0][row_concept_semtype1[0]]));
			uint32_t concept_semtype1_fragment_size = 0;
			smdb_array_4threads_concept_semtype1_col0_decode_UA(concept_semtype1_col0_ptr, concept_semtype1_col0_bytes, concept_semtype1_fragment_size);

			uint32_t thread_size = concept_semtype1_fragment_size/NUM_THREADS;
			uint32_t position = 0;

			for (int i=0; i<NUM_THREADS; i++) {
				arguments[i].start = position;
				position += thread_size;
				arguments[i].end = position;
				arguments[i].thread_id = i;
			}
			arguments[NUM_THREADS-1].end = concept_semtype1_fragment_size;

			for (int i=0; i<NUM_THREADS; i++) {
				pthread_create(&threads[i], NULL, &pthread_smdb_array_4threads_worker, (void *) &arguments[i]);
			}

			for (int i=0; i<NUM_THREADS; i++) {
				pthread_join(threads[i], NULL);
			}
		}
	}


	for (int i=0; i<NUM_THREADS; i++) {
		delete[] concept_semtype1_col0_buffer[i];
	}
	delete[] concept_semtype1_col0_buffer;
	for (int i=0; i<NUM_THREADS; i++) {
		delete[] predication1_col0_buffer[i];
	}
	delete[] predication1_col0_buffer;
	for (int i=0; i<NUM_THREADS; i++) {
		delete[] sentence1_col0_buffer[i];
	}
	delete[] sentence1_col0_buffer;
	for (int i=0; i<NUM_THREADS; i++) {
		delete[] predication2_col0_buffer[i];
	}
	delete[] predication2_col0_buffer;
	for (int i=0; i<NUM_THREADS; i++) {
		delete[] concept_semtype2_col0_buffer[i];
	}
	delete[] concept_semtype2_col0_buffer;
	for (int i=0; i<NUM_THREADS; i++) {
		delete[] concept2_col0_buffer[i];
	}
	delete[] concept2_col0_buffer;

	delete[] sentence1_bool_array;
	delete[] sentence1_spin_lock;


	*null_checks = RC;
	return R;

}

#endif

