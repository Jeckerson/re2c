set(BENCHMARKS
    "submatch_00__http_rfc7230"
    "submatch_01__http_simple"
    "submatch_02__uri_rfc3986"
    "submatch_03__uri_simple"
    "submatch_04__apache_log"
    "submatch_05__datetime"
    "submatch_06__email"
    "submatch_07__ipv4"

    "submatch_10__alt1_2"
    "submatch_11__alt1_4"
    "submatch_12__alt1_8"
    "submatch_13__alt2_2"
    "submatch_14__alt2_4"
    "submatch_15__alt2_8"
    "submatch_16__alt4_2"
    "submatch_17__alt4_4"
    "submatch_18__alt4_8"

    "submatch_20__cat2_0"
    "submatch_21__cat2_4"
    "submatch_22__cat2_8"
    "submatch_23__cat4_0"
    "submatch_24__cat4_2"
    "submatch_25__cat4_4"
    "submatch_26__cat8_0"
    "submatch_27__cat8_1"
    "submatch_28__cat8_2"

    "submatch_30__rep_cat_5_3_2"
    "submatch_31__rep_cat_13_11_7"
    "submatch_32__rep_cat_23_19_17"
    "submatch_33__rep_alt_5_3_2"
    "submatch_34__rep_alt_13_11_7"
    "submatch_35__rep_alt_23_19_17"
    "submatch_36__rep_5_rep_3_rep_2"
    "submatch_37__rep_13_rep_11_rep_7"
    "submatch_38__rep_23_rep_19_rep_17"
)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(ENG_DIR "${CMAKE_CURRENT_BINARY_DIR}/engines")
set(GEN_DIR "${CMAKE_CURRENT_BINARY_DIR}/gen")
set(BIN_DIR "${CMAKE_CURRENT_BINARY_DIR}/bin")
set(PREGEN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/pregen")

set(GEN "")

# kleenex
file(MAKE_DIRECTORY "${ENG_DIR}/kleenex/")
file(MAKE_DIRECTORY "${GEN_DIR}/kleenex/")
set(KLEENEX "${ENG_DIR}/kleenex/kexc")
add_custom_command(
    OUTPUT "${KLEENEX}"
    COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/../_engines/kleenex/getkleenex.sh"
    WORKING_DIRECTORY "${ENG_DIR}/kleenex/"
)
# Masked benchmarks for which Kleenex either generates very large output
# (tens of megabytes of C code), or even causes out of memory condition.
set(KLEENEX_MASKED
    "submatch_34__rep_alt_13_11_7"
    "submatch_35__rep_alt_23_19_17"
    "submatch_37__rep_13_rep_11_rep_7"
    "submatch_38__rep_23_rep_19_rep_17"
)
list(JOIN KLEENEX_MASKED "|" KLEENEX_MASKED_REGEXP)
set(KLEENEX_BENCHMARKS ${BENCHMARKS})
list(FILTER KLEENEX_BENCHMARKS EXCLUDE REGEX "${KLEENEX_MASKED_REGEXP}")
foreach(bench ${KLEENEX_BENCHMARKS})
    set(src_file "${SRC_DIR}/kleenex/${bench}.kex")
    set(gen_file "${GEN_DIR}/kleenex/${bench}.c")
    set(pregen_file "${PREGEN_DIR}/kleenex/${bench}.c")
    # don't regenerate kleenex benchmarks, as kleenex is not actively developed
    # and it cannot be built with the recent cabal / haskell ecosystem
    # if(RE2C_REGEN_BENCHMARKS)
    #     file(RELATIVE_PATH rel_src_file "${CMAKE_CURRENT_BINARY_DIR}" "${src_file}")
    #     file(RELATIVE_PATH rel_gen_file "${CMAKE_CURRENT_BINARY_DIR}" "${gen_file}")
    #     add_custom_command(
    #         OUTPUT "${gen_file}"
    #         COMMAND "${KLEENEX}" compile "${rel_src_file}" --srcout "${rel_gen_file}" --act=false --la=true
    #         COMMAND "${CMAKE_COMMAND}" -E copy_if_different "${gen_file}" "${pregen_file}"
    #         DEPENDS "${src_file}" "${KLEENEX}"
    #     )
    # else()
        add_custom_command(
            OUTPUT "${gen_file}"
            COMMAND "${CMAKE_COMMAND}" -E copy "${pregen_file}" "${gen_file}"
            DEPENDS "${pregen_file}"
        )
    # endif()
    list(APPEND GEN "${gen_file}")
endforeach()

# ragel
file(MAKE_DIRECTORY "${ENG_DIR}/ragel/")
file(MAKE_DIRECTORY "${GEN_DIR}/ragel/")
set(RAGEL "${ENG_DIR}/ragel/ragel7")
add_custom_command(
    OUTPUT "${RAGEL}"
    COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/../_engines/ragel/getragel7.sh"
    WORKING_DIRECTORY "${ENG_DIR}/ragel/"
)
foreach(bench ${BENCHMARKS})
    set(src_file "${SRC_DIR}/ragel/${bench}.rl")
    set(gen_file "${GEN_DIR}/ragel/${bench}.c")
    set(pregen_file "${PREGEN_DIR}/ragel/${bench}.c")
    # optionally regenerate ragel benchmarks if RE2C_REGEN_BENCHMARKS is set
    if(RE2C_REGEN_BENCHMARKS)
        file(RELATIVE_PATH rel_src_file "${CMAKE_CURRENT_BINARY_DIR}" "${src_file}")
        file(RELATIVE_PATH rel_gen_file "${CMAKE_CURRENT_BINARY_DIR}" "${gen_file}")
        add_custom_command(
            OUTPUT "${gen_file}"
            COMMAND "${RAGEL}" "-G2" "${rel_src_file}" -o "${rel_gen_file}"
            COMMAND "${CMAKE_COMMAND}" -E copy_if_different "${gen_file}" "${pregen_file}"
            DEPENDS "${src_file}" "${RAGEL}"
        )
    else()
        add_custom_command(
            OUTPUT "${gen_file}"
            COMMAND "${CMAKE_COMMAND}" -E copy "${pregen_file}" "${gen_file}"
            DEPENDS "${pregen_file}"
        )
    endif()
    list(APPEND GEN "${gen_file}")
endforeach()

# re2c
file(MAKE_DIRECTORY "${ENG_DIR}/re2c/")
file(MAKE_DIRECTORY "${GEN_DIR}/re2c/")
set(RE2C "${CMAKE_BINARY_DIR}/re2c")
set(RE2C3 "${ENG_DIR}/re2c/re2c3")
add_custom_command(
    OUTPUT "${RE2C3}"
    COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/../_engines/re2c/getre2c3.sh"
    WORKING_DIRECTORY "${ENG_DIR}/re2c/"
)
set(RE2C_FLAGS "--reusable" "--tags" "--no-generation-date" "--no-version")
set(COMMON_RE2C
    "${SRC_DIR}/re2c/common.re"
    "${SRC_DIR}/re2c/include/fill.re"
    "${SRC_DIR}/re2c/include/fill_email.re"
    "${SRC_DIR}/re2c/include-eof/fill.re"
    "${SRC_DIR}/re2c/include-eof/fill_email.re"
)
# deprecated algorithms were removed after re2c-3.0
set(DEPRECATED_ALGS "tdfa0" "stadfa")
foreach(bench ${BENCHMARKS})
foreach(eof "" "-eof")
foreach(alg "tdfa1" "tdfa0" "stadfa")
    set(src_file "${SRC_DIR}/re2c/${bench}.re")
    set(gen_file "${GEN_DIR}/re2c/${bench}${eof}-${alg}.c")
    set(pregen_file "${PREGEN_DIR}/re2c/${bench}${eof}-${alg}.c")
    # always regenerate re2c benchmarks, except for deprecated algorithms
    if(RE2C_REGEN_BENCHMARKS OR NOT (alg IN_LIST DEPRECATED_ALGS))
        # for deprecated algorithms use re2c-3.0
        if(alg IN_LIST DEPRECATED_ALGS)
            set(re2c_for_gen "${RE2C3}")
        else()
            set(re2c_for_gen "${RE2C}")
        endif()
        file(RELATIVE_PATH rel_src_file "${CMAKE_CURRENT_BINARY_DIR}" "${src_file}")
        file(RELATIVE_PATH rel_gen_file "${CMAKE_CURRENT_BINARY_DIR}" "${gen_file}")
        file(RELATIVE_PATH rel_inc_path "${CMAKE_CURRENT_BINARY_DIR}" "${SRC_DIR}/re2c/include${eof}")
        set(re2c_flags ${RE2C_FLAGS} "-I" "${rel_inc_path}")
        if("${alg}" STREQUAL "tdfa0")
            set(re2c_flags ${re2c_flags} "--no-lookahead")
        elseif("${alg}" STREQUAL "stadfa")
            set(re2c_flags ${re2c_flags} "--stadfa")
        endif()
        add_custom_command(
            OUTPUT "${gen_file}"
            COMMAND "${re2c_for_gen}" ${re2c_flags} "${rel_src_file}" -o "${rel_gen_file}"
            COMMAND "${CMAKE_COMMAND}" -E copy_if_different "${gen_file}" "${pregen_file}"
            DEPENDS "${src_file}" ${COMMON_RE2C} "${re2c_for_gen}"
        )
    else()
        add_custom_command(
            OUTPUT "${gen_file}"
            COMMAND "${CMAKE_COMMAND}" -E copy "${pregen_file}" "${gen_file}"
            DEPENDS "${pregen_file}"
        )
    endif()
    list(APPEND GEN "${gen_file}")
endforeach()
endforeach()
endforeach()

# binaries
set(OBJ "")
set(BIN "")
set(CFLAGS "-O3" "-I" "${SRC_DIR}")
set(COMMON_SRC "${SRC_DIR}/common.h")
file(MAKE_DIRECTORY "${BIN_DIR}/kleenex/")
file(MAKE_DIRECTORY "${BIN_DIR}/ragel/")
file(MAKE_DIRECTORY "${BIN_DIR}/re2c/")
foreach(gen_file ${GEN})
foreach(compiler "gcc" "clang")
    string(REGEX REPLACE "^${GEN_DIR}(.+)\.c$" "${BIN_DIR}\\1-${compiler}" bin_file "${gen_file}")
    set(obj_file "${bin_file}.o")
    add_custom_command(
        OUTPUT "${bin_file}"
        COMMAND "${compiler}" ${CFLAGS} -c "${gen_file}" -o "${obj_file}"
        COMMAND "${compiler}" ${CFLAGS} "${obj_file}" -o "${bin_file}"
        DEPENDS "${gen_file}" ${COMMON_SRC}
    )
    list(APPEND OBJ "${obj_file}")
    list(APPEND BIN "${bin_file}")
endforeach()
endforeach()

# helper function to transform list
function(regex_replace_list regexp replace var)
    set(result "")
    foreach(arg ${ARGN})
        string(REGEX REPLACE "${regexp}" "${replace}" x "${arg}")
        list(APPEND result "${x}")
    endforeach()
    set(${var} "${result}" PARENT_SCOPE)
endfunction()

# input data
set(DAT)
# Some benchmarks share the same data, like submatch_03__uri_simple and submatch_02__uri_rfc3986.
regex_replace_list("^submatch_[0-9]+__([^_]+).*" "\\1" INPUTS ${BENCHMARKS})
list(REMOVE_DUPLICATES INPUTS)
foreach(input ${INPUTS})
    set(src_dir "${CMAKE_CURRENT_SOURCE_DIR}/../_data/${input}")
    set(dst_dir "${CMAKE_CURRENT_BINARY_DIR}/data/${input}")
    file(GLOB script "${CMAKE_CURRENT_SOURCE_DIR}/../_data/gen.py")
    add_custom_command(
        OUTPUT "${dst_dir}/small"
        COMMAND "${CMAKE_COMMAND}" -E copy "${src_dir}/small" "${dst_dir}/small"
        DEPENDS "${src_dir}/small"
    )
    add_custom_command(
        OUTPUT "${dst_dir}/big"
        COMMAND "${script}"
        DEPENDS "${script}" "${dst_dir}/small"
        WORKING_DIRECTORY "${dst_dir}"
    )
    list(APPEND DAT "${dst_dir}/small" "${dst_dir}/big")
endforeach()

add_custom_target(bench_submatch_aot ALL DEPENDS ${BIN} ${DAT})

# benchmark scripts
set(srcdir "${CMAKE_CURRENT_SOURCE_DIR}")
set(builddir ".")
configure_file(run.py.in run.py @ONLY)

# override default clean command to keep engines (ragel, kleenex)
set_directory_properties(PROPERTY
    CLEAN_NO_CUSTOM On
    ADDITIONAL_CLEAN_FILES "${GEN};${OBJ};${BIN};${DAT}"
)
