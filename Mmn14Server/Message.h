#pragma once
#include <cstdint>
#include <cstring>
#include "Utils.h"

//This makes sense to windows native programers...
enum op {
	r_Backup_file = 100,
	r_get_file = 200,
	r_delete_file = 201,
	r_list_files = 202
};

enum response_status {
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
	uint8_t _op;
	uint16_t _name_len;
	char* _file_name;
}RequestHeader;

typedef struct ResponseHeader_struct
{
	uint8_t _version;
	uint16_t _status;
	uint16_t _name_len;
	char* _file_name;
} ResponseHeader;

//returns bool - accept payload or finish message parsing
int GetRequestHeader(char*, int len, RequestHeader* out_requst_header);