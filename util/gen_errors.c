/*
    This program converts the FreeType error definitions into
    corresponding Python definitions. It only needs to be run
    when there are updates to the former; the output can then
    be copied and pasted into the appropriate part of freetype2.py.

    Copyright 2015 Lawrence D'Oliveiro <ldo@geek-central.gen.nz>.
    Dual-licensed under the FreeType licence
    <http://git.savannah.gnu.org/cgit/freetype/freetype2.git/tree/docs/FTL.TXT>
    and GPLv2 <http://git.savannah.gnu.org/cgit/freetype/freetype2.git/tree/docs/GPLv2.TXT>
    or later, to be compatible with FreeType itself.
*/

#include <stdio.h>

#define FT_NOERRORDEF_(suffix, code, msg) \
    FT_ERRORDEF_(suffix, code, msg)

int main(void)
  {
    fprintf(stdout, "class Error :\n");
    fprintf(stdout, "    \"names for error codes and corresponding message strings.\"\n");
    fprintf(stdout, "    # automatically generated by util/gen_errors.c. Do not hand-edit\n");
    fprintf(stdout, "    # this class; instead, re-run that and replace this with its output.\n");
    fprintf(stdout, "\n    # Error codes:\n");
#define FT_ERRORDEF_(suffix, code, msg) \
    fprintf(stdout, "    %s = %d\n", #suffix, code);
#include <freetype/fterrdef.h>
#undef FT_ERRORDEF_
    fprintf(stdout, "\n    # Mapping from codes to message strings:\n");
    fprintf(stdout, "    Message = \\\n        {\n");
#define FT_ERRORDEF_(suffix, code, msg) \
    fprintf(stdout, "            %d : %s,\n", code, #msg);
#include <freetype/fterrdef.h>
#undef FT_ERRORDEF_
    fprintf(stdout, "        }\n");
    fprintf(stdout, "\n#end Error\n");
    return
        0;
  } /*main*/
