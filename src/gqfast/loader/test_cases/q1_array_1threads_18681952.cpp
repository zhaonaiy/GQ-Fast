#ifndef q1_array_1threads_18681952_
#define q1_array_1threads_18681952_

#include "../fastr_index.hpp"
#include "../global_vars.hpp"

#include <atomic>
#define NUM_THREADS 1

using namespace std;

static args_threading arguments[NUM_THREADS];


static int* R;
static int* RC;

static pthread_spinlock_t* r_spin_locks;

static uint64_t** term1_col0_buffer;
static uint64_t** doc2_col0_buffer;

extern inline void q1_array_1threads_18681952_term1_col0_decode_UA(uint32_t* term1_col0_ptr, uint32_t term1_col0_bytes, uint32_t & term1_fragment_size) __attribute__((always_inline));

void* pthread_q1_array_1threads_18681952_worker(void* arguments);

extern inline void q1_array_1threads_18681952_doc2_col0_decode_UA_threaded(int thread_id, uint32_t* doc2_col0_ptr, uint32_t doc2_col0_bytes, uint32_t & doc2_fragment_size) __attribute__((always_inline));

void q1_array_1threads_18681952_term1_col0_decode_UA(uint32_t* term1_col0_ptr, uint32_t term1_col0_bytes, uint32_t & term1_fragment_size) {

	term1_fragment_size = term1_col0_bytes/4;

	for (uint32_t i=0; i<term1_fragment_size; i++) {
		term1_col0_buffer[0][i] = *term1_col0_ptr++;
	}
}

void* pthread_q1_array_1threads_18681952_worker(void* arguments) {

	args_threading* args = (args_threading *) arguments;

	uint32_t term1_it = args->start;
	uint32_t term1_fragment_size = args->end;
	int thread_id = args->thread_id;

	for (; term1_it < term1_fragment_size; term1_it++) {

		uint32_t term1_col0_element = term1_col0_buffer[0][term1_it];

		uint32_t* row_doc2 = idx[3]->index_map[term1_col0_element];
		uint32_t doc2_col0_bytes = idx[3]->index_map[term1_col0_element+1][0] - row_doc2[0];
		if(doc2_col0_bytes) {

			uint32_t* doc2_col0_ptr = reinterpret_cast<uint32_t *>(&(idx[3]->fragment_data[0][row_doc2[0]]));
			uint32_t doc2_fragment_size = 0;
			q1_array_1threads_18681952_doc2_col0_decode_UA_threaded(thread_id, doc2_col0_ptr, doc2_col0_bytes, doc2_fragment_size);

			for (uint32_t doc2_it = 0; doc2_it < doc2_fragment_size; doc2_it++) {
				uint32_t doc2_col0_element = doc2_col0_buffer[thread_id][doc2_it];

				RC[doc2_col0_element] = 1;

				pthread_spin_lock(&r_spin_locks[doc2_col0_element]);
				R[doc2_col0_element] += 1;
				pthread_spin_unlock(&r_spin_locks[doc2_col0_element]);

			}
		}
	}
	return nullptr;
}

void q1_array_1threads_18681952_doc2_col0_decode_UA_threaded(int thread_id, uint32_t* doc2_col0_ptr, uint32_t doc2_col0_bytes, uint32_t & doc2_fragment_size) {

	doc2_fragment_size = doc2_col0_bytes/4;

	for (uint32_t i=0; i<doc2_fragment_size; i++) {
		doc2_col0_buffer[thread_id][i] = *doc2_col0_ptr++;
	}
}

extern "C" int* q1_array_1threads_18681952(int** null_checks) {

	benchmark_t1 = chrono::steady_clock::now();

	int max_frag;

	max_frag = metadata.idx_max_fragment_sizes[2];
	term1_col0_buffer = new uint64_t*[NUM_THREADS];
	for (int i=0; i<NUM_THREADS; i++) {
		term1_col0_buffer[i] = new uint64_t[max_frag];
	}

	max_frag = metadata.idx_max_fragment_sizes[3];
	doc2_col0_buffer = new uint64_t*[NUM_THREADS];
	for (int i=0; i<NUM_THREADS; i++) {
		doc2_col0_buffer[i] = new uint64_t[max_frag];
	}

	RC = new int[metadata.idx_domains[3][0]]();
	R = new int[metadata.idx_domains[3][0]]();

	r_spin_locks = spin_locks[3];


	uint64_t doc1_list[1];
	doc1_list[0] = 18681952;

	for (int doc1_it = 0; doc1_it<1; doc1_it++) {

		uint64_t doc1_col0_element = doc1_list[doc1_it];

		uint32_t* row_term1 = idx[2]->index_map[doc1_col0_element];
		uint32_t term1_col0_bytes = idx[2]->index_map[doc1_col0_element+1][0] - row_term1[0];
		if(term1_col0_bytes) {

			uint32_t* term1_col0_ptr = reinterpret_cast<uint32_t *>(&(idx[2]->fragment_data[0][row_term1[0]]));
			uint32_t term1_fragment_size = 0;
			q1_array_1threads_18681952_term1_col0_decode_UA(term1_col0_ptr, term1_col0_bytes, term1_fragment_size);

			uint32_t thread_size = term1_fragment_size/NUM_THREADS;
			uint32_t position = 0;

			for (int i=0; i<NUM_THREADS; i++) {
				arguments[i].start = position;
				position += thread_size;
				arguments[i].end = position;
				arguments[i].thread_id = i;
			}
			arguments[NUM_THREADS-1].end = term1_fragment_size;

			for (int i=0; i<NUM_THREADS; i++) {
				pthread_create(&threads[i], NULL, &pthread_q1_array_1threads_18681952_worker, (void *) &arguments[i]);
			}

			for (int i=0; i<NUM_THREADS; i++) {
				pthread_join(threads[i], NULL);
			}
		}
	}


	for (int i=0; i<NUM_THREADS; i++) {
		delete[] term1_col0_buffer[i];
	}
	delete[] term1_col0_buffer;
	for (int i=0; i<NUM_THREADS; i++) {
		delete[] doc2_col0_buffer[i];
	}
	delete[] doc2_col0_buffer;


	*null_checks = RC;
	return R;

}

#endif

