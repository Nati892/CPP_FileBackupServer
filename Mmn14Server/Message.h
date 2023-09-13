#pragma once
#include <cstdint>
#include <cstring>
#include "Utils.h"

#define MAX_FILE_NAME_LENGTH 256
//This makes sense to windows native programers...
enum op :uint16_t {
	r_Backup_file = 100,
	r_get_file = 200,
	r_delete_file = 201,
	r_list_files = 202
};

enum response_status :uint16_t {
	s_list_files = 210,
	s_get_file = 211,
	s_delete_or_backup_success = 212,
	e_file_not_found = 1001,
	e_no_files = 1002,
	e_general_error
};

enum message_parse_position
{
	process_payload,
	messgae_end
};

typedef struct RequestHeader_struct
{
	uint32_t _user_id;//4 bytes
	uint8_t _version;
	op _op;
	uint16_t _name_len;
	char* _file_name;
}RequestHeader;

typedef struct ResponseHeader_struct
{
	uint8_t _version;
	response_status _status;
	uint16_t _name_len;
	char* _file_name;
} ResponseHeader;

//returns bool - accept header, or complete from next Header
bool GetRequestHeader(char* buff, int buff_len, RequestHeader* out_requst_header, int* out_bytes_consumed);
bool OpHasNameField(op _op);