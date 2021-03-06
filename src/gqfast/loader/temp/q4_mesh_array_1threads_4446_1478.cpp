#ifndef q4_mesh_array_1threads_4446_1478_
#define q4_mesh_array_1threads_4446_1478_

#include "../fastr_index.hpp"
#include "../global_vars.hpp"

#define NUM_THREADS 10
#define BUFFER_POOL_SIZE 2

using namespace std;

static args_threading arguments[NUM_THREADS];


static int* R;
static int* RC;

static uint64_t* q4_mesh_array_1threads_4446_1478_intersection_buffer;

extern inline void q4_mesh_array_1threads_4446_1478_doc1_col0_intersection0_decode_UA(uint32_t* doc1_col0_intersection_ptr_0, uint32_t doc1_col0_bytes_intersection0, uint32_t & doc1_intersection0_fragment_size) __attribute__((always_inline));

extern inline void q4_mesh_array_1threads_4446_1478_doc1_col0_intersection1_decode_UA(uint32_t* doc1_col0_intersection_ptr_1, uint32_t doc1_col0_bytes_intersection1, uint32_t & doc1_intersection1_fragment_size) __attribute__((always_inline));

extern inline void q4_mesh_array_1threads_4446_1478_intersection(uint32_t doc1_intersection0_fragment_size, uint32_t doc1_intersection1_fragment_size, uint32_t & q4_mesh_array_1threads_4446_1478_intersection_size) __attribute__((always_inline));

void* pthread_q4_mesh_array_1threads_4446_1478_worker(void* arguments);

extern inline void q4_mesh_array_1threads_4446_1478_term1_col0_decode_UA_threaded(int thread_id, uint32_t* term1_col0_ptr, uint32_t term1_col0_bytes, uint32_t & term1_fragment_size) __attribute__((always_inline));

extern inline void q4_mesh_array_1threads_4446_1478_term1_col1_decode_UA_threaded(int thread_id, unsigned char* term1_col1_ptr, uint32_t term1_fragment_size) __attribute__((always_inline));

void q4_mesh_array_1threads_4446_1478_doc1_col0_intersection0_decode_UA(uint32_t* doc1_col0_intersection_ptr_0, uint32_t doc1_col0_bytes_intersection0, uint32_t & doc1_intersection0_fragment_size) {

	doc1_intersection0_fragment_size = doc1_col0_bytes_intersection0/4;

	for (uint32_t i=0; i<doc1_intersection0_fragment_size; i++) {
		buffer_arrays[3][0][0][0][i] = *doc1_col0_intersection_ptr_0++;
	}
}

void q4_mesh_array_1threads_4446_1478_doc1_col0_intersection1_decode_UA(uint32_t* doc1_col0_intersection_ptr_1, uint32_t doc1_col0_bytes_intersection1, uint32_t & doc1_intersection1_fragment_size) {

	doc1_intersection1_fragment_size = doc1_col0_bytes_intersection1/4;

	for (uint32_t i=0; i<doc1_intersection1_fragment_size; i++) {
		buffer_arrays[3][0][0][1][i] = *doc1_col0_intersection_ptr_1++;
	}
}
void q4_mesh_array_1threads_4446_1478_intersection(uint32_t doc1_intersection0_fragment_size, uint32_t doc1_intersection1_fragment_size, uint32_t & q4_mesh_array_1threads_4446_1478_intersection_size) { 

	if (doc1_intersection0_fragment_size == 0) { return; }

	if (doc1_intersection1_fragment_size == 0) { return; }

	uint32_t intersection_index = 0;
	uint32_t* its = new uint32_t[2]();
	bool end = false;

	while(!end) {

		bool match = true;
		while (1) {
			if (buffer_arrays[3][0][0][0][its[0]]  != buffer_arrays[3][0][0][1][its[1]]) {
				match = false;
				break;
			}

			break;
		}

		if (match) {
			q4_mesh_array_1threads_4446_1478_intersection_buffer[intersection_index++] = buffer_arrays[3][0][0][0][its[0]];
			while(1) {
				if (++its[0] == doc1_intersection0_fragment_size) {
					end = true;
					break;
				}
				if (++its[1] == doc1_intersection1_fragment_size) {
					end = true;
					break;
				}

				break;
			}
		}
		else {

			uint64_t smallest = buffer_arrays[3][0][0][0][its[0]];
			int index_of_smallest = 0;
			uint32_t fragment_size_of_smallest = doc1_intersection0_fragment_size;

			if (smallest > buffer_arrays[3][0][0][1][its[1]]) {
				smallest = buffer_arrays[3][0][0][1][its[1]];
				index_of_smallest = 1;
				fragment_size_of_smallest = doc1_intersection1_fragment_size;
			}

			if (++its[index_of_smallest] == fragment_size_of_smallest) {
				end = true;
			}
		}
	}

	delete[] its;
	q4_mesh_array_1threads_4446_1478_intersection_size = intersection_index;
}

void* pthread_q4_mesh_array_1threads_4446_1478_worker(void* arguments) {

	args_threading* args = (args_threading *) arguments;

	uint32_t q4_mesh_array_1threads_4446_1478_intersection_it = args->start;
	uint32_t q4_mesh_array_1threads_4446_1478_intersection_size = args->end;
	int thread_id = args->thread_id;

	for (; q4_mesh_array_1threads_4446_1478_intersection_it<q4_mesh_array_1threads_4446_1478_intersection_size; q4_mesh_array_1threads_4446_1478_intersection_it++) {

		uint32_t* row_term1 = idx[2]->index_map[q4_mesh_array_1threads_4446_1478_intersection_buffer[q4_mesh_array_1threads_4446_1478_intersection_it]];
		uint32_t term1_col0_bytes = idx[2]->index_map[q4_mesh_array_1threads_4446_1478_intersection_buffer[q4_mesh_array_1threads_4446_1478_intersection_it]+1][0] - row_term1[0];
		if(term1_col0_bytes) {

			uint32_t* term1_col0_ptr = reinterpret_cast<uint32_t *>(&(idx[2]->fragment_data[0][row_term1[0]]));
			uint32_t term1_fragment_size = 0;
			q4_mesh_array_1threads_4446_1478_term1_col0_decode_UA_threaded(thread_id, term1_col0_ptr, term1_col0_bytes, term1_fragment_size);

			unsigned char* term1_col1_ptr = &(idx[2]->fragment_data[1][row_term1[1]]);
			q4_mesh_array_1threads_4446_1478_term1_col1_decode_UA_threaded(thread_id, term1_col1_ptr, term1_fragment_size);

			for (uint32_t term1_it = 0; term1_it < term1_fragment_size; term1_it++) {
				uint32_t term1_col0_element = buffer_arrays[2][0][thread_id][0][term1_it];
				unsigned char term1_col1_element = buffer_arrays[2][1][thread_id][0][term1_it];

				RC[term1_col0_element] = 1;

				pthread_spin_lock(&spin_locks[2][term1_col0_element]);
				R[term1_col0_element] += term1_col1_element;
				pthread_spin_unlock(&spin_locks[2][term1_col0_element]);

			}
		}
	}
	return nullptr;
}

void q4_mesh_array_1threads_4446_1478_term1_col0_decode_UA_threaded(int thread_id, uint32_t* term1_col0_ptr, uint32_t term1_col0_bytes, uint32_t & term1_fragment_size) {

	term1_fragment_size = term1_col0_bytes/4;

	for (uint32_t i=0; i<term1_fragment_size; i++) {
		buffer_arrays[2][0][thread_id][0][i] = *term1_col0_ptr++;
	}
}

void q4_mesh_array_1threads_4446_1478_term1_col1_decode_UA_threaded(int thread_id, unsigned char* term1_col1_ptr, uint32_t term1_fragment_size) {

	for (uint32_t i=0; i<term1_fragment_size; i++) {
		buffer_arrays[2][1][thread_id][0][i] = *term1_col1_ptr++;
	}
}

extern "C" int* q4_mesh_array_1threads_4446_1478(int** null_checks) {

	benchmark_t1 = chrono::steady_clock::now();

	int max_frag;

	max_frag = metadata.idx_max_fragment_sizes[2];
	for(int i=0; i<metadata.idx_num_encodings[2]; i++) {
		for (int j=0; j<NUM_THREADS; j++) {
			buffer_arrays[2][i][j] = new uint64_t*[BUFFER_POOL_SIZE];
			for (int k=0; k<BUFFER_POOL_SIZE; k++) {
				buffer_arrays[2][i][j][k] = new uint64_t[max_frag];
			}
		}
	}

	max_frag = metadata.idx_max_fragment_sizes[3];
	for(int i=0; i<metadata.idx_num_encodings[3]; i++) {
		for (int j=0; j<NUM_THREADS; j++) {
			buffer_arrays[3][i][j] = new uint64_t*[BUFFER_POOL_SIZE];
			for (int k=0; k<BUFFER_POOL_SIZE; k++) {
				buffer_arrays[3][i][j][k] = new uint64_t[max_frag];
			}
		}
	}

	RC = new int[metadata.idx_domains[2][0]]();
	R = new int[metadata.idx_domains[2][0]]();


	q4_mesh_array_1threads_4446_1478_intersection_buffer = new uint64_t[metadata.idx_max_fragment_sizes[3]];

	uint32_t* row_doc1_intersection0 = idx[3]->index_map[4446];
	uint32_t doc1_col0_bytes_intersection0 = idx[3]->index_map[4446+1][0] - row_doc1_intersection0[0];
	uint32_t* doc1_col0_intersection_ptr_0 = reinterpret_cast<uint32_t *>(&(idx[3]->fragment_data[0][row_doc1_intersection0[0]]));
	uint32_t doc1_intersection0_fragment_size = 0;
	q4_mesh_array_1threads_4446_1478_doc1_col0_intersection0_decode_UA(doc1_col0_intersection_ptr_0, doc1_col0_bytes_intersection0, doc1_intersection0_fragment_size);

	uint32_t* row_doc1_intersection1 = idx[3]->index_map[1478];
	uint32_t doc1_col0_bytes_intersection1 = idx[3]->index_map[1478+1][0] - row_doc1_intersection1[0];
	uint32_t* doc1_col0_intersection_ptr_1 = reinterpret_cast<uint32_t *>(&(idx[3]->fragment_data[0][row_doc1_intersection1[0]]));
	uint32_t doc1_intersection1_fragment_size = 0;
	q4_mesh_array_1threads_4446_1478_doc1_col0_intersection1_decode_UA(doc1_col0_intersection_ptr_1, doc1_col0_bytes_intersection1, doc1_intersection1_fragment_size);

	uint32_t q4_mesh_array_1threads_4446_1478_intersection_size = 0;
	q4_mesh_array_1threads_4446_1478_intersection(doc1_intersection0_fragment_size, doc1_intersection1_fragment_size, q4_mesh_array_1threads_4446_1478_intersection_size);

	uint32_t thread_size = q4_mesh_array_1threads_4446_1478_intersection_size/NUM_THREADS;
	uint32_t position = 0;

	for (int i=0; i<NUM_THREADS; i++) {
		arguments[i].start = position;
		position += thread_size;
		arguments[i].end = position;
		arguments[i].thread_id = i;
	}
	arguments[NUM_THREADS-1].end = q4_mesh_array_1threads_4446_1478_intersection_size;

	for (int i=0; i<NUM_THREADS; i++) {
		pthread_create(&threads[i], NULL, &pthread_q4_mesh_array_1threads_4446_1478_worker, (void *) &arguments[i]);
	}

	for (int i=0; i<NUM_THREADS; i++) {
		pthread_join(threads[i], NULL);
	}


	for (int j=0; j<metadata.idx_num_encodings[2]; j++) {
		for (int k=0; k<NUM_THREADS; k++) {
			for (int l=0; l<BUFFER_POOL_SIZE; l++) {
				delete[] buffer_arrays[2][j][k][l];
			}
			delete[] buffer_arrays[2][j][k];
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
	delete[] q4_mesh_array_1threads_4446_1478_intersection_buffer;


	*null_checks = RC;
	return R;

}

#endif

